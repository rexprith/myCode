//Author: Prithwiraj Shome
//This is an example code to showcase usage of Posix Threads
//
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

#define NUM_THREADS  2 // Total number of threads to be created. Increase this number to increase number of threads to be created.

using namespace std;

void *Thread_Routine(void *arg);

class PosixThreadClass
{
	private:
	int count;
       	pthread_t threadID[NUM_THREADS];
	void *(*func_table[NUM_THREADS])(void *);
	
	public:
	PosixThreadClass()
	{
	    cout << "Class Constructor" << endl;
	    count = 5;
	    for (int c = 0; c < NUM_THREADS; c++){
	    	func_table[c] = Thread_Routine;
	    }
	}

	~PosixThreadClass()
	{
	    cout << "Class Destructor" << endl;
	    count = 0;
	}

	int ThreadCreator ()
	{
	    int ret = 0;
	    cout << "In Thread Creator function" << endl;
	    for (int n = 0; n < NUM_THREADS; n++)
	    {
	    	cout << "Thread Number = " << n << endl;
		ret = pthread_create(&threadID[n], NULL, func_table[n],&count);
	        pthread_join(threadID[n],NULL);
	    }
	    return ret;
	}
	
};

int main (void)
{
    int ret = 0;
    PosixThreadClass *ptrCls = new PosixThreadClass;
    ret = ptrCls->ThreadCreator();
    delete ptrCls;
    return 0;
}

void *Thread_Routine(void *arg)
{  
    int cnt = *((int *)arg);
    pid_t tid = syscall(__NR_gettid);
    do {
        cout << __TIME__ << " Thread ID: " << tid << " execution count = " << cnt-- << endl;
	sleep(1);
    }while(cnt > 0);
    return NULL;
}

