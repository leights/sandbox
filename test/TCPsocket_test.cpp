#include "../core/include/TCPsocket.h"

int main() {
	TCPsocket sock(9999, "0.0.0.0");
	sock.Listen();
	TCPsocket * newsock = sock.Accept();

	char buff[1024];
	while (int len = newsock->Recv(buff)) {
                buff[len] = '\0';
                newsock->Send(buff, len);
        }

	sleep(1000);
}
