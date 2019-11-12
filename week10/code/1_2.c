#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int g=10;
int main(void )
{
	int t=20;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("vfork failed! \n");
		exit(-1);
	}
	else if (pid ==0)
	{
		printf("before child pid =%d ,&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
		g=100;
		t=200;
		s=300;
		printf("after child pid =%d,g=%d,t=%d,s=%d\n",getpid(),g,t,s);
		sleep(3);
	}
	else{
		printf("parent pid =%d ,&g=%p,&t=%p,&s=%p\n",getpid(),&g,&t,&s);
		printf("parent pid =%d,g=%d,t=%d,s=%d\n",getpid(),g,t,s);	
	}

}
