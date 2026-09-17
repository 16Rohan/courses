#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include "selrep.h"

// Global flag to track which specific frame timed out
void timeout_handler(int sig) {
    printf("\n[Client] Alarm Triggered for unacknowledged frame(s). Resending window...\n");
}

int main() {
    int s, bytes;
    int base = 0;
    int next_seq_num = 0;
    char data[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int total_frames = strlen(data);
    
    struct sockaddr_in server;
    struct ack a;

    // Track ACK status for frames currently in flight
    int ack_received[MAX_FRAMES] = {0};

    s = socket(AF_INET, SOCK_STREAM, 0);
    signal(SIGALRM, timeout_handler);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(s, (struct sockaddr *)&server, sizeof(server));

    printf("--- Selective Repeat Protocol Client ---\n");
    printf("Sending Data: %s\n", data);
    printf("Window Size: %d, Total Frames: %d\n\n", WINDOW_SIZE, total_frames);

    while (base < total_frames) {
        // 1. Send all unacknowledged frames within the window limit
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < total_frames) {
            if (!ack_received[next_seq_num]) {
                struct frame f;
                f.seq_no = next_seq_num;
                f.total_frame = total_frames;
                f.payload = data[next_seq_num];
                f.is_eof = (next_seq_num == total_frames - 1) ? 1 : 0;

                printf("[Client] Sending Frame %d (Payload: %c)\n", f.seq_no, f.payload);
                send(s, &f, sizeof(f), 0);
            }
            next_seq_num++;
        }

        // 2. Start timer and wait for an individual ACK
        alarm(TIMEOUT_SEC);
        bytes = recv(s, &a, sizeof(a), 0);
        alarm(0); // Cancel alarm immediately

        if (bytes > 0) {
            printf("[Client] Received Individual ACK for Frame %d\n", a.ack_no);
            
            // Mark this specific frame as acknowledged
            if (a.ack_no < MAX_FRAMES) {
                ack_received[a.ack_no] = 1;
            }

            // Slide the window base forward as long as consecutive frames are acknowledged
            while (base < total_frames && ack_received[base]) {
                base++;
            }
        } 
        else if (errno == EINTR) {
            // Timeout occurred! Selective Repeat retransmits ONLY unacknowledged frames in the window
            printf("[Client] TIMEOUT! Retransmitting unacknowledged frames from base %d...\n", base);
            next_seq_num = base; // Reset transmission pointer back to base to resend unacked frames
        } 
        else {
            perror("[Client] Connection error");
            break;
        }
    }

    printf("\n[Client] All frames sent and individually acknowledged successfully!\n");
    close(s);
    return 0;
}