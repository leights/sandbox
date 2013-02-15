#include "../include/TCPConnectionManager.h"

#ifndef __TCPCONNECTIONMANAGER
#define __TCPCONNECTIONMANAGER

TCPConnectionManager::TCPConnectionManager() {running = true;}
TCPConnectionManager::TCPConnectionManager(int numconnections, int port, std::string address)
{
	LOG(0, std::string("Initiating new TPConnectionManager."));
	running =true;
	listener = new TCPlistener(port, address, this);
	numConnections = numconnections;
	listeningPort = port;
	listeningAddress = address;
	connected = 0;
}

bool TCPConnectionManager::NewConnection(TCPsocket * sock) {
	LOG(0, std::string("New Connection detected.  We need to check to see if there are too many connections already."));
	if (connected < numConnections) {
		LOG(0, std::string("We have an avaiable connection."));
		LOG(5, std::string("Creating new connection."));
		clients[connected] = new TCPclient(sock);
		clients[connected++]->Start(NULL);
	} else {
		LOG(5, std::string("Too many connections already.  Closing connection."));
		sock->close();
		return false;
	}
	return true;
}

void TCPConnectionManager::Execute(void* args) {
	listener->Start(NULL);
	while (running) {
		//CheckThreads();
	}
}

void TCPConnectionManager::Setup() {}

#endif
