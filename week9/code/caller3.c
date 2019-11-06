#include "my.h"
int main()
{
	int ret;
	char *arg[]={"./test1","123","456","Hello","world",NULL};
	printf("calller3 :pid : %d,ppid : %d\n",getpid(),getppid());
	execv("/home/why/linuxprogram/week9/code/test1",arg);
	printf("execv after calling\n");
	return 0;
}
