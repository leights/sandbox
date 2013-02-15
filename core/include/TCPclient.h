#ifndef __TCPCLIENT
#define __TCPCLIENT

#include "Thread.h"
#include "TCPsocket.h"
#include <iostream>

using namespace std;


class TCPclient : public Thread {
	TCPsocket * socket;
	void clientStarted() {std::cout << "Started a new client." << std::endl;}
	int process(char*,int);	
public:
	TCPclient();
	TCPclient(TCPsocket*);
	void Execute(void*);
	void Setup();
	
};

#endif
