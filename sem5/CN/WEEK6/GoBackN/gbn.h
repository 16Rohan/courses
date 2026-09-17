#ifndef GBN_H
#define GBN_H

#include<stdio.h>
#include<string.h>

#define PORT 6969
#define SERVER_IP "127.0.0.1"
#define WINDOW_SIZE 4
#define TIMEOUT_SEC 2

struct frame{
    int seq_no;
    int total_frame;
    char payload; // I Want Payload to be a single byte
    char is_eof;
};

struct ack{
    int ack_no;
};

#endif