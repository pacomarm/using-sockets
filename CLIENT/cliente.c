
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

char c1 = 'A';
char c2 = 'B';
int i = 16;
char c3 = 'C';
char c4 = 'D';

void send_chars(int sock, char* buffer);
char *j = (char*)&i;


int main(int argc, char *argv[]){
    int sock = connection();
    
    char buffer[256];

    snprintf(buffer, sizeof(buffer), "%c%c%d%d%d%d%c%c", c1, c2, j[3], j[2], j[1], j[0], c3, c4);    
    send_chars(sock, buffer);
    
    close(sock);
    return 0;
}


void send_chars(int sock, char* buffer){

    printf("%s", buffer);

    // Sending data
    if(send(sock, buffer, sizeof(buffer)+1, 0) < 0) {
        printf("The information has not been sent\n");
        exit(1);
    }
}