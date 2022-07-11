#include <process_copy.h>

typedef struct 
{
	const char* sfile;
	const char* dfile;
	int blocksize;
	int flags;
}lpc;

void *jobs(void*arg)
{
	lpc* pgr=(lpc*)arg;
	//调用拷贝函数
	copy(pgr->sfile,pgr->dfile,pgr->blocksize,pgr->flags);
	return NULL;
}

int process_create(const char* sfile, const char* dfile, int blocksize, int pronum)
{
	
	lpc arg;
	
	//改变线程初始状态为分离态
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_t tid;
	
	int flag;
	int err;
	for (flag = 0; flag < pronum; flag++)
	{
		//定义结构体向线程函数传入
		int flag1;
		flag1=flag*blocksize;
		arg.sfile=sfile;
		arg.dfile=dfile;
		arg.blocksize=blocksize;
		arg.flags=flag1;
		//判断县城是否创建成功
		if((err=pthread_create(&tid,&attr,jobs,(void*)&arg))>0)
		{
			printf("thread create error:%s\n",strerror(err));
			exit(0);
	
		}
		sleep(1);
	}
	pthread_attr_destroy(&attr);
	return 0;
}
