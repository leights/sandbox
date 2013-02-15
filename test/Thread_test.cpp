#include "../core/include/Thread.h"
#include <iostream>
#include "../core/include/Logger.h"
#include <sstream>

using namespace std;
const int NUMTHREADS = 2;
void run();

class Tester {
public:
	int x;
	int y;
	int z;
};

class Thread_consumer : public Thread {
	std::ostringstream msg;
public:
	int count;
	//static int Thread_consumer::i;
	static int i;
	Thread_consumer() : Thread() {
	}
	void Setup() {};
	void Execute(void* arg) {
		Execute_consumer();
	}
	void Execute_consumer() {
		msg << __FILE__  << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << "Created consumer.";
		Logger::Log(msg.str());
		count = 0;
		Tester * str;
		msg.str(std::string());
		msg << __FILE__  << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << "Value for i is " << i;
		Logger::Log(msg.str());
		while (i == 1) {
			WaitForMessages();
			while ((str = (Tester*)GetMessage()) != NULL)
			{
				count++;
				for (int i = 0; i <= 0; i++)
				{
				str->z = str->x * str->y;
				str->z = str->x * str->y;
				str->z = str->x * str->y;
				str->z = str->x * str->y;
				str->z = str->x / str->y;
				str->z = str->x / str->y;
				str->z = str->x / str->y;
				str->z = str->x / str->y;
				}
				deleteItem(str);
			}
		}	
		delete in_Messages;
		delete out_Messages;
		pthread_exit(NULL);
	}

	void deleteItem(void * item) {
		delete ((Tester*)item);
	}
};

class Thread_producer : public Thread {
        int count;
        Thread_consumer * t;
	std::ostringstream msg;
public:
	static int i;
	Thread_producer() : Thread() {
		count = 0;
	}
	void Setup() {};
	void Execute(void* arg) {
		msg.clear();
		msg << __FILE__  << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << "Created producer.";
		Logger::Log(msg.str());
        	while (i == 1) {
			if (count != 0 && count % 10000000 == 0) {
				msg.str(std::string());
				msg << __FILE__  << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << "Added 10000000 messages.";
				//std::cout << __FILE__  << ":" << __LINE__ << ":" << __FUNCTION__ << ":" << "Added 1000 messages." << std::endl;
				Logger::Log(msg.str());
			}
			Tester * te = new Tester();
	        	te->x = 10;
        		te->y = 15;
                	t[count++ % NUMTHREADS].PushMessage((void*)te);
        	}
	}
	void SetConsumers(Thread_consumer * ts) {
		t = ts;
	}	
};

int Thread_producer::i = 1;
int Thread_consumer::i = 1;


int main() {
	run();
	std::ostringstream msg;
	msg.str(std::string());
	msg << "Processing complete.";
	Logger::Log(msg.str());
	sleep(3000);
	return 0;
}

void run() {
	Logger log;
	log.Start(NULL);
	std::ostringstream msg;
	int count = 0;
	Thread_consumer t[NUMTHREADS];
	Thread_producer p[NUMTHREADS];
	for (int i = 0; i < NUMTHREADS; t[i++].Start(NULL));
	for (int i = 0; i < NUMTHREADS; i++) { 
		p[i].SetConsumers(t);
		p[i].Start(NULL);
	}
	sleep(10);
	Thread_producer::i = 0;
	sleep(10);
	Thread_consumer::i = 0;
	sleep(10);
	for (int i = 0; i < NUMTHREADS; i++) {
		msg.str(std::string());
		msg << "Thread " << i << " processed " << t[i].count << " messages.";
		Logger::Log(msg.str());
	}
}
