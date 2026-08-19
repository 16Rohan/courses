#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<strings.h>
#include <unistd.h>

int main(){
    int sockfd, i, n;
    char buff1[80], buff2[80];
    struct sockaddr_in serv_addr;

    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(65535);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("Socket Error!");
        exit(1);
    }

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        perror("Connect Error!");
        exit(1);
    }

    printf("Client Starts: \n");
    fflush(stdout);

    for(i = 0; i < 5; i++){
        write(1, "Enter any messsage: ", 19);
        n = read(0, buff1, 80);
        send(sockfd, buff1, n, 0);
        n = recv(sockfd, buff2, 80, 0);
        write(1, "Client has recieved: ", 21);
        write(1, buff2, n);
    }

    close(sockfd);
    exit(0);
}