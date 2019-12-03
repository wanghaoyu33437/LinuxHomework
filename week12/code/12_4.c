#include "my.h"
int main()
{
	pid_t p;
	int fd[2];
	if(pipe(fd)==-1)
	{
		fprintf(stderr,"create pipe error reason:[%s]\n",strerror(errno));
		return -1;	
	}
	p=fork();
	if(p<0)
	{
		fprintf(stderr,"create child error reason:[%s]\n",strerror(errno));
		return -2;	
	}
	
	else if(p==0)
	{
		printf("[child] : pid =%d,ppid = %d\n",getpid(),getppid());
		close(fd[0]);
		sleep(50);
		exit(0);
	}
	else{
		close(fd[1]);
		wait(NULL);
		return 0;
		
	}
}
