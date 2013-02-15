#include "../include/Logger.h"

std::queue<LogMessage> * Logger::inlogs = new std::queue<LogMessage>();;
pthread_mutex_t Logger::logmutex;

LogMessage::LogMessage(std::string f, int l, std::string fun, int le , std::string m) {
	time(&mytime);
	file = f;
	line = l;
	function = fun;
	level = le;
	message = m;
}

Logger::Logger() {
	started = false;
	pthread_mutex_init(&logmutex, NULL);
	outlogs = new std::queue<LogMessage>();
}

void Logger::switchq() {
	std::queue<LogMessage> * tmp;
	pthread_mutex_lock(&logmutex);
	tmp = inlogs;
	inlogs = outlogs;
	outlogs = tmp;
	pthread_mutex_unlock(&logmutex);
}

void Logger::Log(std::string m) {
	LogMessage msg(std::string(), 0, std::string(), 5, m);;
	pthread_mutex_lock(&logmutex);
	inlogs->push(msg);
	pthread_mutex_unlock(&logmutex);
}

void Logger::Log(std::string f, int l, std::string fun, int le, std::string m) {
	LogMessage msg(f , l, fun, le, m);;
        pthread_mutex_lock(&logmutex);
        inlogs->push(msg);
        pthread_mutex_unlock(&logmutex);
}

void Logger::Setup() {}

void Logger::Execute(void* args) {
	LogMessage message;
	while (running) {
		switchq();
		while (outlogs->size() > 0) {
			message = outlogs->front();
			std::cout << message.GetMessage() << std::endl;
			outlogs->pop();
		}
		//std::cout << "Logger thread sleeping." << std::endl;
		sleep(1);
	}
}
