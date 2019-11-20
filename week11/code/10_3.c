#include "my.h"
int main()
{
	pid_t pid;
	int r,status;
	pid=fork();
	if(pid<0)
	{
		perror("failed fork!\n");
		return -1;		
	}
	else if (pid==0)
	{
		printf("child %d is running \n",getpid());
		printf("child will exit\n");
		//while(1);
		exit(120);	
	}
	else
	{
		printf("parent waitting child %d is to exit! \n",pid);
		r=wait(&status);	
		printf("child %d is finished return code =%d \n",r,WEXITSTATUS(status));
		printf("parent %d is running !\n",getpid())	;
return 0;
	}
	
}
