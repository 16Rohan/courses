#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int i, j, sockfd, newsockfd, n, cli_addr_len;
  char buff[80];
  struct sockaddr_in cli_addr, serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    perror("Socket Error!");
    exit(1);
  }

  bzero(&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(65535);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror("Bind Error!");
    exit(1);
  }

  listen(sockfd, 5);

  for (i = 0; i < 5; i++)
  {
    cli_addr_len = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
    if (newsockfd < 0)
    {
      perror("Accept Error!");
      continue;
    }

    if (fork() == 0)
    {
      close(sockfd);

      for (j = 0; j < 5; j++)
      {
        n = recv(newsockfd, buff, 80, 0);
        if (n <= 0)
          break;

        write(1, "Server Received: ", 17);
        write(1, buff, n);
        send(newsockfd, buff, n, 0);
      }

      close(newsockfd);
      exit(0);
    }

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}