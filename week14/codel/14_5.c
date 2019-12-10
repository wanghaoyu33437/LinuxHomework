#include "my.h"
void * fun(void *arg)
{
	int k =(int ) arg;
	printf("worker ----%d : pthread_self return %p\n",k,(void*)pthread_self());

	printf("worker ----%d : will exit\n",k);
	pthread_exit(NULL);
}

int main()
{
	int NUM=5;
	pthread_t tid[NUM];
	int ret[NUM],i;
	for(i=0;i<NUM;i++){
	ret[i]=pthread_create(&tid[i],NULL,fun,(void *)i);
	if(ret[i]!=0)
	{
		perror("create failed! \n");
		return -1;
	}
	pthread_join(tid[i],NULL);
	
	}
printf("Maseter %d : All Dones \n ",getpid());
return 0;
}	
