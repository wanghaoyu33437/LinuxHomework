#include "my.h"
int main()
{
	int ret;
	printf("calller1 :pid : %d,ppid : %d\n",getpid(),getppid());
	ret=system("./test1 123 456  hello world");
	printf("After calling! ret=%d \n",ret);
	sleep(20);
	return 0;
}
