#include "../include/TCPlistener.h"


TCPlistener::TCPlistener(int port, std::string address, TCPConnectionManager * m) {
	manager = m;
	socket = new TCPsocket(port, address);
}

void TCPlistener::Setup() {}

void TCPlistener::Execute(void * args) {
	listen();
	while(manager->NewConnection(socket->Accept()));
}

void TCPlistener::listen() {
	socket->Listen();
}
