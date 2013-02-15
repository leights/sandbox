#include "../include/socket.h"

int socket_create(int type) {
	return socket(AF_INET,type,0);
}

int socket_bind(int socket, int port, char * addr) {
	struct sockaddr_in sockaddr;
        bzero(&sockaddr, sizeof(sockaddr));
        sockaddr.sin_family=AF_INET;
        sockaddr.sin_addr.s_addr = inet_addr(addr);
        sockaddr.sin_port=htons(port);
	return bind(socket, (struct sockaddr *)&sockaddr, sizeof(sockaddr));	
}

int socket_listen(int socket) {
	return listen(socket, 10);
}

int socket_connect();

int socket_recv(int socket, char * buff, int size) {
	return recv(socket, buff, size, 0);
}

int socket_accept(int socket, struct sockaddr_in * addr, socklen_t * size) {
	return accept(socket, (struct sockaddr *)addr, size);
}

int socket_send(int socket, char * buff, int size) {
	return send(socket, buff, size, 0);
}

void socket_close(int socket) {
	close(socket);
}
