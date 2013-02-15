#include "../include/TCPsocket.h"

TCPsocket::TCPsocket() {
	m_socket = socket_create(SOCK_STREAM);
} 

TCPsocket::TCPsocket(int sock) {
	m_socket = sock;
} 

TCPsocket::TCPsocket(int port, std::string addr) {
	m_port = port;
	m_saddress = addr;
	m_socket = socket_create(SOCK_STREAM);
}

bool TCPsocket::Listen() {
	m_connected = true;
	int err = 0;
	if ((err = socket_bind(m_socket, m_port, (char*)m_saddress.c_str())) < 0)
		m_connected = false;
	if (socket_listen(m_socket) < 0)
		m_connected = false;
	return m_connected;
}

bool TCPsocket::Connect() {
	return m_connected;
}

TCPsocket * TCPsocket::Accept() {
	struct sockaddr_in dest;
	socklen_t socksize;
	TCPsocket * t = new TCPsocket(socket_accept(m_socket, &dest, &socksize));
	return t;
}

int TCPsocket::Recv(char * buff) {
	return socket_recv(m_socket, buff, 1024);
}

int TCPsocket::Send(char * buff, int len) {
	return socket_send(m_socket, buff, len);
}

void TCPsocket::close() {
	socket_close(m_socket);
}
