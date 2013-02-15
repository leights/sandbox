#include <iostream>
#include "../core/include/socket.h"

using namespace std;

int main() {
	int packet_size = 1024;
	char buff[packet_size];
	struct sockaddr_in serv;
	struct sockaddr_in dest;

	socklen_t socksize;

	int sock = socket_create(SOCK_STREAM);
	cout << socket_bind(sock, 9999, "0.0.0.0") << endl;
	cout << socket_listen(sock) << endl;

	int clientsock = socket_accept(sock, &dest, &socksize); 
	printf("Incoming connection from %s\n", inet_ntoa(dest.sin_addr));

	while (int len = socket_recv(clientsock, buff, packet_size)) {
		buff[len] = '\0';
		cout << "received " << len << " bytes : " << buff << endl;
		socket_send(clientsock, buff, len);
	} 
}
