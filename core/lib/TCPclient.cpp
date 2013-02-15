#include "../include/TCPclient.h"

TCPclient::TCPclient() {};
TCPclient::TCPclient(TCPsocket*s) {
	socket = s;
}
void TCPclient::Setup() {};
void TCPclient::Execute(void*arg) {
	char buff[1024];	
	clientStarted();
	while (int len = socket->Recv(buff)) {
		process(buff,len);
	}	
}
int TCPclient::process(char * buff, int len) {
	cout << buff << endl;
	socket->Send(buff,len);
} 
