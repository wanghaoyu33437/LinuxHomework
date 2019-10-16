#include "staticlib.h"
#include <stdio.h>

int main(){
	int *a;
	int n=5;
	a=malloc(sizeof(int)*n);
	initarray(a,n);
	showarray(a,5);
	printf("max= %4d\n",max(a,5));
	printf("sum= %4d\n",sum(a,5));
	return 0;

}
