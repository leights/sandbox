#ifndef __TCPLISTENER
#define __TCPLISTENER

#include "TCPsocket.h"
#include "Thread.h"
#include "TCPConnectionManager.h"
#include <string>

class TCPConnectionManager;


class TCPlistener : public Thread {
	TCPsocket * socket;
	TCPConnectionManager * manager;
	
	void listen();
public:
	TCPlistener(int,std::string,TCPConnectionManager*);
	void Execute(void*);
	void Setup();
};

#endif
