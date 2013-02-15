#include "socket.h"
#include <string>

#ifndef __TCPSOCKET
#define __TCPSOCKET

class TCPsocket {
	int m_socket;
	int m_port;

	std::string m_saddress; 

	bool m_connected;
public:
	TCPsocket();
	TCPsocket(int);
	TCPsocket(int, std::string);
	bool Connect();
	bool Listen();
	TCPsocket * Accept();
	int Recv(char *);
	int Send(char *, int);
	void close();

};

#endif
