#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main()
{
	int choice;
	
	while(1)
	{
	choice=menu();
	switch(choice)
	{		
		case 0:
			exit(0);
			break;
		case 1:
			mkdirFile();
			break;	
		case 2:
			wFile();
			break;
		case 3:
			rFile();
			break;	
		case 4:
			chmodFile();
			break;
		case 5:
			showAndChomdFile();
			break;
		default:
			break;
	}
	printf("\n");
}
	return 0;
	
}
