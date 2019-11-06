#include "my.h"
int main()
{
	int ret;
	printf("calller2 :pid : %d,ppid : %d\n",getpid(),getppid());
	execl("/home/why/linuxprogram/week9/code/test1","./test1","123","456","hello","world",NULL);

	printf("execl After calling! \n");

	return 0;
}
