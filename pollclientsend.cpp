#include <netdb.h>
#include <stdio.h>
// #include <stdlib.h>
#include "unistd.h"
#include <string.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 1024
#define PORT 9034
#define SA struct sockaddr
void func(int sockfd)
{
    char buff[MAX];

    bzero(buff, sizeof(buff));
    strcpy(buff, "hi from pollclient send ! \n");

    send(sockfd, buff, sizeof(buff), 0);

    printf("send to all %s\n", buff);
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        return 1;
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        return 1;
    }
    else
    {
        printf("connected to the server..\n");
    }
    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}