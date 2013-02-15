#ifndef __TCPConnectionManager
#define __TCPConnectionManager

#include "TCPsocket.h"
#include "Thread.h"
#include "TCPclient.h"
#include "TCPlistener.h"
#include "Logger.h"

class TCPlistener;


class TCPConnectionManager : public Thread {
	TCPlistener * listener;	
	int listeningPort;
	int numConnections;
	std::string listeningAddress;
	TCPclient * clients[1024];
	int connected;
	bool running;
public:
	TCPConnectionManager();
	TCPConnectionManager(int);
	TCPConnectionManager(int,int,std::string);
	bool NewConnection(TCPsocket*);
	void Execute(void*);
	void Setup();
};

#endif
