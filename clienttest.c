#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
// #include <stdlib.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close
#include <pthread.h>
#include <assert.h>

void *cientThread(void *arg)
{
    printf("In thread\n");
    char message[1024];

 
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create the socket.
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure settings of the server address
    // Address family is Internet
    serverAddr.sin_family = AF_INET;

    // Set port number, using htons function
    serverAddr.sin_port = htons(5008);

    // Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Connect the socket to the server using the address
    addr_size = sizeof serverAddr;
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, addr_size))
    {
        perror("connect\n");
        return NULL;
    }
    strcpy(message, "HAL");

    // for (int i = 0; i < 1000; i++)
    // {
    send(clientSocket, message, strlen(message), 0);

    // }
    // printf("finished pushing 100 \n");

    bzero(message, sizeof(message));

    if (recv(clientSocket, message, 1024, 0) < 0)
    {
        printf("Recv failed\n");
    }
    printf("from server %s\n", message);
    // printf("%s\n", message   17);
    // char *helper_pointer;
    // int index;

    // helper_pointer = strchr(message, 'i');
    // index = (int)(helper_pointer - message);
    // printf("index %d\n", index);
    assert(message[0] == 'i');
    assert(message[1] == 'b');
    assert(message[2] == 'm');

    close(clientSocket);
    // pthread_exit(NULL);
    return NULL;
}

void *cientThreadaaa(void *arg)
{
    printf("In thread\n");
    char message[1024];


    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    // Create the socket.
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure settings of the server address
    // Address family is Internet
    serverAddr.sin_family = AF_INET;

    // Set port number, using htons function
    serverAddr.sin_port = htons(5008);

    // Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    // Connect the socket to the server using the address
    addr_size = sizeof serverAddr;
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, addr_size))
    {
        perror("connect\n");
        return NULL;
    }
    strcpy(message, "aaa");

    // for (int i = 0; i < 1000; i++)
    // {
    send(clientSocket, message, strlen(message), 0);

    // }
    // printf("finished pushing 100 \n");

    bzero(message, sizeof(message));

    if (recv(clientSocket, message, 1024, 0) < 0)
    {
        printf("Recv failed\n");
    }
    printf("from server %s\n", message);
    // printf("%s\n", message   17);
    // char *helper_pointer;
    // int index;

    // helper_pointer = strchr(message, 'i');
    // index = (int)(helper_pointer - message);
    // printf("index %d\n", index);
    assert(message[0] == 'B');
    assert(message[1] == 'B');
    assert(message[2] == 'B');

    close(clientSocket);
    return NULL;
    // pthread_exit(NULL);
}

int main()
{
    int i = 0;
    pthread_t tid[15];
    while (i < 14)
    {
        if (pthread_create(&tid[i], NULL, cientThread, NULL) != 0)
            printf("Failed to create thread\n");
        usleep(5000);
        i++;
    }
    sleep(1);
    i = 0;
    while (i < 14)
    {
        pthread_join(tid[i++], NULL);
        printf("thread end number %d:\n", i);
    }

    // pthread_t tid1;
    // if (pthread_create(&tid1, NULL, cientThreadaaa, NULL) != 0)
    // {
    //     printf("Failed to create thread\n");
    // }
    // pthread_join(tid1, NULL);
    // printf("thread end number %d:\n", i);

    // pthread_t tid2;
    // if (pthread_create(&tid2, NULL, cientThread, NULL) != 0)
    // {
    //     printf("Failed to create thread\n");
    // }
    // pthread_join(tid2, NULL);

    // pthread_t tid3;
    // if (pthread_create(&tid3, NULL, cientThread, NULL) != 0)
    // {
    //     printf("Failed to create thread\n");
    // }
    // pthread_join(tid3, NULL);

    // pthread_t tid4;
    // if (pthread_create(&tid4, NULL, cientThread, NULL) != 0)
    // {
    //     printf("Failed to create thread\n");
    // }
    // pthread_join(tid4, NULL);

    return 0;
}