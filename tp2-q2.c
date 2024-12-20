#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

//We start the main function with arguments from the command line
int main(int argc, char *argv[])
{
    // We check if the user gave exactly 2 arguments
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // We get the server address, and the file name  
    char *host = argv[1];  // Server address
    char *file = argv[2];

    //We print the arguments to confirm them
    printf("Host : %s\n", argv[1]);
    printf("File : %s\n", argv[2]);

    // We initialize the structures to resolve the server address
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints, 0, sizeof(struct addrinfo));

    // We resolve the server address
    getaddrinfo(host, NULL, &hints, &res);
    struct addrinfo *current = res;

    while(current->ai_next != NULL)
    {
        printf("\nFound one result : \n");

        char string_target[128] = {0};
        char string_server[128] = {0};
        getnameinfo(current->ai_addr, current->ai_addrlen, string_target, 128, string_server, 128, NI_NUMERICHOST | NI_NUMERICSERV);

        printf("\t Host : %s\n", string_target);
        printf("\t Serv : %s\n", string_server);

        current = current->ai_next;
    }

    exit(EXIT_SUCCESS);
}