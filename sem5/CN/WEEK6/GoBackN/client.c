#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h> // Required for EINTR
#include "gbn.h"

void timeout_handler(int sig)
{
    printf("\n[Client] Alarm Triggered. Resending window...\n");
}

int main()
{
    int s, bytes;
    int base = 0;
    int next_seq_num = 0;
    char data[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int total_frames = strlen(data);

    struct sockaddr_in server;
    struct ack a;

    s = socket(AF_INET, SOCK_STREAM, 0);
    signal(SIGALRM, timeout_handler);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(s, (struct sockaddr *)&server, sizeof(server));

    printf("Sending Data: %s\n", data);
    printf("Window Size: %d, Total Frames: %d\n\n", WINDOW_SIZE, total_frames);

    // Go-Back-N Sliding Window Loop
    while (base < total_frames)
    {
        // Send all frames within the current window limit
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < total_frames)
        {
            struct frame f;
            f.seq_no = next_seq_num;
            f.total_frame = total_frames;
            f.payload = data[next_seq_num];
            f.is_eof = (next_seq_num == total_frames - 1) ? 1 : 0;

            printf("[Client] Sending Frame %d (Payload: %c)\n", f.seq_no, f.payload);
            send(s, &f, sizeof(f), 0);

            next_seq_num++;
        }

        // Start timer and wait for ACK
        alarm(TIMEOUT_SEC);
        bytes = recv(s, &a, sizeof(a), 0);
        alarm(0); // Cancel alarm immediately so it doesn't fire later

        if (bytes > 0)
        {
            printf("[Client] Received ACK for %d\n", a.ack_no);
            base = a.ack_no + 1; // Slide window forward
        }
        else if (errno == EINTR)
        {
            // Timeout occurred! Go-Back-N resets next_seq_num to base for retransmission
            next_seq_num = base;
        }
        else
        {
            perror("[Client] Connection error");
            break;
        }
    }

    printf("\nAll frames sent and acknowledged successfully!\n");
    close(s);
    return 0;
}