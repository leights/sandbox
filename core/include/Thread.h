#include <pthread.h>
#include <queue>
#include <time.h>

#ifndef __THREAD
#define __THREAD

class Thread
{
public:
	Thread(); 
	int Start(void * arg);
	void PushMessage(void*);
protected:
	int Run(void * arg);
	static void * EntryPoint(void*);
	virtual void Setup();
	virtual void Execute(void*);
	void * Arg() const {return Arg_;}
	void Arg(void* a){Arg_ = a;}
	void * GetMessage();
	int WaitForMessages();
	void SwapQueue();
	void Stop();

	bool running;

	std::queue<void*> * in_Messages;
	std::queue<void*> * out_Messages;
private:
	pthread_t thread;
	pthread_mutex_t messagemutex;
	pthread_cond_t messagecond;

	int ThreadId_;
	void * Arg_;
};

#endif
