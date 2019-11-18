#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
static void __attribute__((constructor)) before_main()
{
	printf("***************Before Main\n"); 
}
static void __attribute__((destructor)) after_main()
{
	printf("***************After Main\n"); 
}
static void callback1(void)
{
	printf("***************Callback1 is running\n");
}
static void callback2(void)
{
	printf("***************Callback2 is running\n");
}
static void callback3(void)
{
	printf("Callback3 is running\n");
}
int main(void )
{
	int i;
	atexit(callback1);
	atexit(callback2);
	FILE*fp;
	char buf[]={"hello world"};
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("failed to create file\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF){
		perror("failed to fputs file\n");
		return -1;	
	}
	printf("test message!");
	//exit(0);	
	_exit(0);
	
	//return 0;
}
