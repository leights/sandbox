#include "../core/include/Logger.h"
#include <sstream>

int main() {
	sleep(5);
	std::ostringstream msg;
	Logger l;
	l.Start(NULL);
	for (int i = 0; i < 1000; i++) {
		msg.str(std::string());
		msg << "This is a message " << i;
		Logger::Log(msg.str());
	}
	sleep(1);
	for (int i = 100; i < 2000; i++) {
		msg.str(std::string());
		msg << "This is a message " << i;
		Logger::Log(msg.str());
	}
	for (int i = 200; i < 3000; i++) {
		msg.str(std::string());
		msg << "This is a message " << i;
		Logger::Log(msg.str());
	}
	sleep(10);
}
