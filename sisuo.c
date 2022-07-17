
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;
int code1=1;
int code2=2;

void* jobs1(void* arg)
{
	pthread_detach(pthread_self());
	pthread_mutex_lock(&lock1);
	sleep(1);
	printf("线程1%x\ncode1==%d\n",(unsigned int)pthread_self(),code1++);
	sleep(1);
	pthread_mutex_lock(&lock2);
	printf("线程2%x\ncode2==%d\n",(unsigned int)pthread_self(),code2++);
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
}
void* jobs2(void* arg)
{
	pthread_detach(pthread_self());
	pthread_mutex_lock(&lock2);
	sleep(1);
	printf("线程2%x\ncode2==%d\n",(unsigned int)pthread_self(),code2++);
	sleep(1);
	pthread_mutex_lock(&lock1);
	printf("线程1%x\ncode1==%d\n",(unsigned int)pthread_self(),code1++);
	pthread_mutex_unlock(&lock1);

	pthread_mutex_unlock(&lock2);
	
}


int main(void)
{
	pthread_t tid;
	pthread_create(&tid,NULL,jobs1,NULL);
	pthread_create(&tid,NULL,jobs2,NULL);
	
	while(1)
	{
		sleep(1);
	}


	return 0;
}
