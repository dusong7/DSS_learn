#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>

char host_name[20];
int port = 8000;

int main() {
    struct sockaddr_in sin, pin;
    int sock_descriptor, temp_sock_descriptor;
    int i, len, on = 1;
    char buf[16384];

    sock_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port);
    if(bind(sock_descriptor, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    {
        perror("call to bind");
        exit(1);
    }

    if (listen(sock_descriptor, 100) == -1)
    {
        perror("Call to listen");
        exit(1);
    }

    printf("Accepting connection....\n");
    while(1)
    {
        socklen_t address_size = sizeof(pin);
        temp_sock_descriptor = accept(sock_descriptor, (struct sockaddr * )&pin, &address_size);
        if (temp_sock_descriptor == -1)
        {
            perror("Call to accept");
            exit(1);
        }
        if(recv(temp_sock_descriptor, buf, 16384,0) == -1)
        {
            perror("call to recv");
            exit(1);
        }

        inet_ntop(AF_INET, &pin.sin_addr, host_name, sizeof(host_name));
        printf("received from client(%s) : %s", host_name, buf);
        len = strlen(buf);
        int i = 0;
        for (i = 0; i < len; ++i) {
            buf[i] = toupper(buf[i]);

        }

        if(send(temp_sock_descriptor, buf, len+1, 0) == -1)
        {
            perror("call to send");
            exit(1);
        }
        close(temp_sock_descriptor);
    }

    return 0;
}