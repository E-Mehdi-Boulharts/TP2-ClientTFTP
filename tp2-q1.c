#include <stdio.h>
#include <stdlib.h>

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
    char *file = argv[2];  // File name to send or receive

    //We print the arguments to confirm them
    printf("Host : %s\n", argv[1]);
    printf("File : %s\n", argv[2]);

    exit(EXIT_SUCCESS);
}