#include "my.h"
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t rwlock;
//当开启线程互斥锁之后，文件读写锁不影响
int g=0;

void *fun(void *param)
{
	int i;
	pthread_rwlock_rdlock(&rwlock);
	for(i=0;i<LOOP;i++){
		pthread_mutex_lock(&mutex);
		g++;
		//printf("thread %d is running,g == %d\n",(int) param,g);
		pthread_mutex_unlock(&mutex);
	}
	pthread_rwlock_unlock(&rwlock);
	return NULL;


}

int main()
{
	pthread_t tid[NUM];
	int i,ret;
	ret= pthread_rwlock_init(&rwlock,NULL);
	if(ret)
	{
		perror("rwlock  init failed\n");
		exit(1);
	}
	pthread_rwlock_wrlock(&rwlock);
	for(i=0;i<NUM;i++)
	{
		ret=pthread_create(&tid[i],NULL,fun,(void*)i);
		if(ret!=0)
		{
			perror("thread init failed!\n");
			exit(2);
		}
	}
	pthread_rwlock_unlock(&rwlock);
	for(i=0;i<NUM;i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	printf("thread num----------%d\n",NUM);
	printf("LOOP per thread-----%d\n",LOOP);
	printf("expect result-------%d\n",NUM*LOOP);
	printf("actual result-------%d\n",g);

}
