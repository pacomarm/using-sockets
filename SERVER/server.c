
#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

char c1 = 'U';
char c2 = 'U';
long i = -1;
char c3 = 'U';
char c4 = 'U';

int main(int argc, char *argv[])
{
    int socket_desc = initialization();
    
    while(1) {
        
        int client_sock = connection(socket_desc);
        char string[9];
        int read_size = recv(client_sock, &string, sizeof(char)*9, 0); // reading the char array of size 9: A,B,0,0,0,16,C,D
        c1 = string[0]; // saving A
        c2 = string[1]; // saving B
        char strP[5]; // creating a string of size five: A,B,0,0,0,16,C,D
        strP[0] = string[2]; // saving 0
        strP[1] = string[3]; // saving 0
        strP[2] = string[4]; // saving 0
        strP[3] = string[5]; // saving 1
        strP[4] = string[6]; // saving 6
        char *endptr; // create null pointer
        i = strtol(strP, &endptr, 10); // converting char arrat to long in little endian
        c3 = string[7]; // saving C
        c4 = string[8]; // saving D

        printf("c1: %c\n", c1);
        printf("c2: %c\n", c2);
        printf("i: %ld\n", i);
        printf("c3: %c\n", c3);
        printf("c4: %c\n", c4);
    }
    
    close(socket_desc);
    return 0;
}

