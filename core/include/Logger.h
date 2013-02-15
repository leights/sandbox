#ifndef __LOGGER
#define __LOGGER

#include "Thread.h"
#include <queue>
#include <string>
#include <iostream>
#include <pthread.h>
#include <time.h>

#define LOG(x,y) Logger::Log(__FILE__, __LINE__, __FUNCTION__, x, y)

class LogMessage {
	time_t mytime;	
	std::string file;
	int line;
	std::string function;
	int level;
	std::string message;
public:
	LogMessage() {}
	LogMessage(std::string, int, std::string, int, std::string);

	std::string GetMessage() {return message;}
};

class Logger : public Thread {
	void switchq();
        static pthread_mutex_t logmutex;

	static std::queue<LogMessage> * inlogs;	
	std::queue<LogMessage> * outlogs;	
	bool started;
public:
	Logger();
	static void Log(std::string);
	static void Log(std::string, int, std::string, int, std::string);
	void Setup();
	void Execute(void*);
};

#endif
