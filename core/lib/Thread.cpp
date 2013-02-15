#include "../include/Thread.h"

Thread::Thread() 
{
	Arg_ = NULL;
	pthread_mutex_init(&messagemutex, NULL);
	pthread_cond_init(&messagecond, NULL);

	in_Messages = new std::queue<void*>();
	out_Messages = new std::queue<void*>();

	running = false;
}

int Thread::Start(void * arg)
{
	Arg(arg); // store user data
	int code = pthread_create(&thread, NULL, EntryPoint, (void *)this);
	running = true;
	return code;
}

int Thread::Run(void * arg)
{
	Setup();
	Execute( arg );
}

void * Thread::EntryPoint(void * pthis)
{
	Thread * pt = (Thread*)pthis;
	pt->Run( pt->Arg() );
}

void Thread::Setup()
{
	// Do any setup here
}

void Thread::Execute(void* arg)
{
	// Your code goes here
}

void Thread::PushMessage(void * m)
{
	pthread_mutex_lock(&messagemutex);
	in_Messages->push(m);
	//pthread_cond_signal(&messagecond);	
	pthread_mutex_unlock(&messagemutex);
}

void * Thread::GetMessage()
{
	if (out_Messages->size() == 0)
		return NULL;
	void * ret = out_Messages->front();
	out_Messages->pop();
	return ret;
}

int Thread::WaitForMessages()
{
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	ts.tv_sec += 1; // ten seconds
	pthread_cond_timedwait(&messagecond, &messagemutex, &ts);
	SwapQueue();
	//pthread_mutex_unlock(&messagemutex);
	return 0;
}

void Thread::SwapQueue() {
	std::queue<void*> * tmp = in_Messages;
	in_Messages = out_Messages; 
	out_Messages = tmp;
	pthread_mutex_unlock(&messagemutex);
}

void Thread::Stop() {
	running = false;
}
