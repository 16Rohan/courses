#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "gbn.h"

int main()
{
    int s, c;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr *)&server, sizeof(server));
    listen(s, 5);

    printf("[Server] Listening on port %d...\n", PORT);
    c = accept(s, (struct sockaddr *)&client, &len);
    printf("[Server] Client connected.\n\n");

    int expected_seq_num = 0;
    char received_data[100];
    int data_idx = 0;
    struct frame f;

    while (1)
    {
        int bytes_received = recv(c, &f, sizeof(f), 0);
        if (bytes_received <= 0)
        {
            printf("[Server] Client disconnected or error occurred.\n");
            break;
        }

        // Check if the received frame is the one we are expecting in order
        if (f.seq_no == expected_seq_num)
        {
            printf("[Server] Received expected Frame %d (Payload: %c)\n", f.seq_no, f.payload);

            // Store payload into our reconstructed string buffer
            received_data[data_idx++] = f.payload;
            received_data[data_idx] = '\0';

            // Send cumulative ACK back to client
            struct ack a;
            a.ack_no = f.seq_no;
            send(c, &a, sizeof(a), 0);
            printf("[Server] Sent ACK for %d\n", a.ack_no);

            expected_seq_num++;

            // If this was the last frame, break out of loop
            if (f.is_eof)
            {
                printf("\n[Server] End of transmission reached.\n");
                break;
            }
        }
        else
        {
            // Out of order or duplicate frame received
            printf("[Server] Received out-of-order Frame %d (Expected %d). Discarding.\n", f.seq_no, expected_seq_num);

            // Resend ACK for the last successfully received in-order frame
            // (If expected_seq_num is 0, ack_no will be -1, keeping base at 0)
            struct ack a;
            a.ack_no = expected_seq_num - 1;
            send(c, &a, sizeof(a), 0);
            printf("[Server] Sent previous ACK for %d\n", a.ack_no);
        }
    }

    printf("\n[Server] Successfully Reconstructed Data: %s\n", received_data);

    close(c);
    close(s);
    return 0;
}