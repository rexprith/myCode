//Author: Prithwiraj Shome
//Example code to showcase Posix Message Queue operation between a message sender and receiver thread
//
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NUM_THREADS  2
#define QUEUE_NAME   "/mq_name"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

using namespace std;

void *Sender_Thread_Routine(void *arg);
void *Receiver_Thread_Routine(void *arg);


class PosixThreadClass
{
	private:
	int count;
       	pthread_t threadID[NUM_THREADS];
	void *(*func_table[NUM_THREADS])(void *) = {Sender_Thread_Routine,Receiver_Thread_Routine};
	
	public:
	PosixThreadClass()
	{
	    cout << "Class Constructor" << endl;
	    count = 5;
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
    mqd_t mq;
    
    struct mq_attr mq_attr;
    mq_attr.mq_flags = 0; 
    mq_attr.mq_maxmsg = MAX_MESSAGES;
    mq_attr.mq_msgsize = MAX_MSG_SIZE;
    mq_attr.mq_curmsgs = 0;

    mq = mq_open(QUEUE_NAME, O_CREAT | O_EXCL, QUEUE_PERMISSIONS ,&mq_attr);
    if (mq != -1)
    {
        PosixThreadClass *ptrCls = new PosixThreadClass;
        ret = ptrCls->ThreadCreator();
        delete ptrCls;
    
    	mq_close(mq);
    	mq_unlink(QUEUE_NAME);
    }
    return ret;
}

void *Sender_Thread_Routine(void *arg)
{  
    int cnt = *((int *)arg);
    pid_t tid = syscall(__NR_gettid);
    mqd_t sendMq;
    unsigned int prio = 0;
    sendMq = mq_open(QUEUE_NAME, O_WRONLY);
    if (sendMq != -1) {
	do {
	    if (-1 == mq_send (sendMq, "Prithwiraj Shome",MAX_MSG_SIZE,prio)) {
	    	cout << __TIME__ << " Thread ID: "<< tid << " Message "<< cnt-- << " Sending Failed" <<endl;
	    }
	    else {

	    	cout << __TIME__ << " Thread ID: "<< tid << " Message "<< cnt-- << " Sending Success" <<endl;
	    } 
	    sleep(1);
        }while(cnt > 0);
    }
    mq_close(sendMq);
    return NULL;
}

void *Receiver_Thread_Routine(void *arg)
{
    int cnt = *((int *)arg);
    pid_t tid = syscall(__NR_gettid);
    mqd_t recvMq;
    unsigned int prio = 0;
    recvMq = mq_open(QUEUE_NAME, O_RDONLY);
    char buff[MAX_MSG_SIZE];
    if(recvMq != -1) {
    	do {
		if (-1 == mq_receive(recvMq,buff,MAX_MSG_SIZE,&prio)) {  
	    	    cout << __TIME__ << " Thread ID: "<< tid << " Message " << cnt-- << " Receiving Failed" << endl;
		}
		else {
	    	    cout << __TIME__ << " Thread ID: " << tid << " Message " << cnt-- <<" Receive Success"  << endl;
		}
		sleep(1);
    	}while(cnt > 0);
    }
    mq_close(recvMq);
    return NULL;
}
