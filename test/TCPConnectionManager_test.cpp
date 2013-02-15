#include "../core/include/TCPConnectionManager.h"
#include "../core/include/Logger.h"

int main() {
	Logger l;
	l.Start(NULL);	
	TCPConnectionManager m(10, 9999, "0.0.0.0");
	m.Start(NULL);
	sleep(100000);
	return 0;
}
