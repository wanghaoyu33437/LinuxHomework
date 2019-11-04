#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <dlfcn.h>
int main()
{
	void *hd;
	int (*f0)(),(*f1)(),(*f2)(),(*f3)(),(*f4)(),(*f5)();
	char *error;
	int choice;
	hd=dlopen("./libdylib.so",RTLD_LAZY);
	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f0=dlsym(hd,"menu");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f1=dlsym(hd,"mkdirFile");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f2=dlsym(hd,"wFile");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);	
	}
	f3=dlsym(hd,"rFile");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);
			
	}
	f4=dlsym(hd,"chmodFile");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);
			
	}
	f5=dlsym(hd,"showAndChomdFile");
	if((error=dlerror())!=NULL){
	fprintf(stderr,"%s\n",dlerror());
		exit(1);
			
	}

	while(1)
	{
	choice=f0();
	switch(choice)
	{		
		case 0:
			exit(0);
			break;
		case 1:
			f1();
			break;	
		case 2:
			f2();
			break;
		case 3:
			f3();
			break;	
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;
		default:
			break;
	}
	printf("\n");
}
	return 0;
	
}
