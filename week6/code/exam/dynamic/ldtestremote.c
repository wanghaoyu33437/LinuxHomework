#include "dylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n=5;
	int *a;
	a=malloc(sizeof(int)*n);
	initarray(a,n);
	showarray(a,n);
	printf("max= %4d\n",max(a,5));
	printf("sum= %4d\n",sum(a,5));
	return 0;

}
