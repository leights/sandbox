#ifndef __SOCKET
#define __SOCKET

#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#include<stdio.h>
#include<stdlib.h>


#define bzero(p, size) (void)memset((p), 0, (size))


int socket_create(int);
int socket_connect();
int socket_bind(int,int,char*);
int socket_listen(int);
int socket_recv(int,char *,int);
int socket_send(int, char *, int);
int socket_accept(int, struct sockaddr_in *, socklen_t *);
void socket_close(int);

#endif
