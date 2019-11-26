#include "my.h"

int main(){

	pid_t p1,p2,p3;
	int s1,s3,s2;
	p1=fork();
	if(p1<0)
	{
		perror("fork failed\n");
		return -1;
	}
	else if (p1==0)
	{
		printf("[child] pid : %d,[parent] pid :%d\n",getpid(),getppid());
		exit(0);
	}
	else{
		p2=fork();
		if(p2<0)
		{
			perror("fork failed\n");
			return -1;
		}
		else if (p2==0)
		{
			printf("[child] pid : %d,[parent] pid :%d\n",getpid(),getppid());
			exit(0);
		}
		else{
			p3=fork();
			if(p3<0)
			{
				perror("fork failed\n");
				return -1;
			}
			else if (p3==0)
			{
				printf("[child] pid : %d,[parent] pid :%d\n",getpid(),getppid());
				exit(0);
			}
			else{
				p1=wait(&s1);
				p2=wait(&s2);
				p3=wait(&s3);
				printf("%d exit code %d \n %d exit code %d \n %d exit code %d\n",p1,WEXITSTATUS(s1),p2,WEXITSTATUS(s2),p3,WEXITSTATUS(s3));
			return 0;
			}
		}
	}

}
