#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "selrep.h"

int main() {
    int s, c;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr *)&server, sizeof(server));
    listen(s, 5);

    printf("--- Selective Repeat Protocol Server ---\n");
    printf("[Server] Listening on port %d...\n", PORT);
    c = accept(s, (struct sockaddr *)&client, &len);
    printf("[Server] Client connected.\n\n");

    int window_base = 0;
    char receive_buffer[MAX_FRAMES];
    int is_buffered[MAX_FRAMES] = {0};
    int data_idx = 0;
    struct frame f;

    while (1) {
        int bytes_received = recv(c, &f, sizeof(f), 0);
        if (bytes_received <= 0) {
            printf("[Server] Client disconnected or error occurred.\n");
            break;
        }

        // Check if the frame falls within the receiver's window bounds
        if (f.seq_no >= window_base && f.seq_no < window_base + WINDOW_SIZE) {
            printf("[Server] Received Frame %d (Payload: %c) within window.\n", f.seq_no, f.payload);

            // Buffer the frame payload and mark it as received
            receive_buffer[f.seq_no] = f.payload;
            is_buffered[f.seq_no] = 1;

            // Send an INDIVIDUAL acknowledgment for this specific frame
            struct ack a;
            a.ack_no = f.seq_no;
            send(c, &a, sizeof(a), 0);
            printf("[Server] Sent Individual ACK for %d\n", a.ack_no);

            // Deliver consecutive buffered frames to the application layer and slide window
            while (is_buffered[window_base]) {
                printf("[Server] Delivering in-order Frame %d ('%c') to application.\n", 
                       window_base, receive_buffer[window_base]);
                
                window_base++;
            }
        } 
        else if (f.seq_no < window_base) {
            // Duplicate frame (already acknowledged previously), re-acknowledge it
            printf("[Server] Received duplicate Frame %d. Resending ACK.\n", f.seq_no);
            struct ack a;
            a.ack_no = f.seq_no;
            send(c, &a, sizeof(a), 0);
        } 
        else {
            // Frame is outside the current receive window (too far ahead)
            printf("[Server] Frame %d is outside window range [%d - %d]. Discarding.\n", 
                   f.seq_no, window_base, window_base + WINDOW_SIZE - 1);
        }

        // Check if transmission is complete (all expected elements delivered)
        // For a 26-character string, once window_base reaches 26, we are done.
        if (f.is_eof && is_buffered[f.seq_no]) {
            // Verify if everything up to EOF is processed
            int all_done = 1;
            for(int i = 0; i <= f.seq_no; i++) {
                if(!is_buffered[i]) { all_done = 0; break; }
            }
            if(all_done) {
                // Reconstruct final string to verify
                char reconstructed[100];
                for(int i = 0; i <= f.seq_no; i++) {
                    reconstructed[i] = receive_buffer[i];
                }
                reconstructed[f.seq_no + 1] = '\0';
                printf("\n[Server] End of transmission reached.\n");
                printf("[Server] Successfully Reconstructed Data: %s\n", reconstructed);
                break;
            }
        }
    }

    close(c);
    close(s);
    return 0;
}