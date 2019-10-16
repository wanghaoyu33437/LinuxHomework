#include "dylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


int main(){
	void *hd;
	void(*f1)();
	int(*f2)(),(*f3)();
	char*error;
	int n=5;
	int *a;
	a=malloc(sizeof(int)*n);
	initarray(a,n);
	showarray(a,n);
	hd=dlopen("../../dynamiclib/libdylib.so",RTLD_LAZY);
	printf("max= %4d\n",max(a,5));
	printf("sum= %4d\n",sum(a,5));
	return 0;

}
