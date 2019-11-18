#include "my.h"
#pragma pack(4)
struct test1{
	char i;
	short k;
	char a[3];
	int s;
};
int main()
{
	struct test1 a ;
	printf("----address of \ni=%16p\nk=%16p\na=%16p\ns=%16p\n",&a.i,&a.k,a.a,&a.s);
printf("size of struct test1 =%ld\n",sizeof(struct test1));
return 0;
}
