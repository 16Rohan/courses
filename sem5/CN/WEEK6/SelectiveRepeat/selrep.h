#ifndef SELREP_H
#define SELREP_H

#include <stdio.h>
#include <string.h>

#define PORT 6969
#define SERVER_IP "127.0.0.1"
#define WINDOW_SIZE 4       // Size of the Selective Repeat window
#define TIMEOUT_SEC 2       // Retransmission timeout in seconds
#define MAX_FRAMES 100

struct frame {
    int seq_no;
    int total_frame;
    char payload; 
    char is_eof;
};

struct ack {
    int ack_no;             // Individual acknowledgment for a specific sequence number
};

#endif