#include "my.h"
int main()
{
	int ret;
	//char *arg[]={"./test1","123","456","Hello","world",NULL};
	printf("calller4 :pid : %d,ppid : %d\n",getpid(),getppid());
	execlp("test1","./test1","123","456","Hello","world",NULL);
	//execv("/home/why/linuxprogram/week9/code/test1",arg);
	printf("execlp after calling\n");
	return 0;
}
