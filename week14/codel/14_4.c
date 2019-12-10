#include "my.h"
void * fun(void *arg)
{
	int TID =pthread_self();
	printf("worker ----%d : gettid return %d\n",TID,TID);
	printf("worker ----%d : pthread_self return %p\n",TID,TID);
	printf("worker ----%d : will exit\n",TID);
}

int main()
{
	pthread_t tid;
	int ret;
	ret=pthread_create(&tid,NULL,fun,NULL);
	if(ret !=0)
	{
		perror("create failed! \n");
		return -1;
	}
	pthread_join(tid,NULL);
	ret=pthread_create(&tid,NULL,fun,NULL);
	if(ret !=0)
	{
		perror("create failed! \n");
		return -1;
	}
	pthread_join(tid,NULL);
	printf("Maseter %d : All Dones \n ",getpid());
	return 0;
}	
