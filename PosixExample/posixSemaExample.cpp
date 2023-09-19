//Author: Prithwiraj Shome
//Example code to showcase Posix Message Queue operation between a message sender and receiver thread
//
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NUM_THREADS  2
#define SEM_NAME   "/mq_name"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

using namespace std;

void *Thread1_Routine(void *arg);
void *Thread2_Routine(void *arg);


sem_t Sem;

class PosixThreadClass
{
	private:
	int count;
	void *(*func_table[NUM_THREADS])(void *) = {Thread1_Routine,Thread2_Routine};
	
	public:
       	pthread_t threadID[NUM_THREADS];
	PosixThreadClass()
	{
	    cout << "Class Constructor" << endl;
	    count = 1;
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
	    }
	    return ret;
	}
	
};

int main (void)
{
    int ret = 0;
    ret = sem_init(&Sem, 0, NUM_THREADS);
    
    if (ret != -1) {
    	PosixThreadClass *ptrCls = new PosixThreadClass;

    	ret = ptrCls->ThreadCreator();

	pthread_join(ptrCls->threadID[0],NULL);
	pthread_join(ptrCls->threadID[1],NULL);
    	delete ptrCls;
    }
    return ret;
}

//Thread 1 Routine
void *Thread1_Routine(void *arg)
{  
    int cnt = *((int *)arg);    
    int retv = 0;
    int val = 0;
    pid_t tid = syscall(__NR_gettid);
    
    do {
	retv = sem_wait(&Sem);
	
	if (retv >= 0) {	
   	
	    cout << __TIME__ << " Thread ID: "<< tid << " Execution Count = " << cnt-- << endl;
            sleep(1);
    	    sem_post(&Sem);
	}
	else {
	    sem_getvalue(&Sem, &val);
	    cout << "Thread 1 Blocked: Sem Val = "<< val << endl;
	}

    }while(cnt > 0);
    
    return NULL;
}

//Thread 2 Routine
void *Thread2_Routine(void *arg)
{
    int cnt = *((int *)arg);
    int retv = 0;
    int val = 0;
    pid_t tid = syscall(__NR_gettid);

    do {
	retv = sem_wait(&Sem);
	if (retv >= 0) {
	    cout << __TIME__ << " Thread ID: "<< tid << " Execution Count = " << cnt-- << endl;
	    sleep(1);
	    sem_post(&Sem);
	}
	else {
	    sem_getvalue(&Sem, &val);
	    cout << "Thread 2 Blocked: Sem Val = "<< val << endl;
	}

    }while(cnt > 0);
    
    return NULL;
}
