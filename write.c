#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a[50]={};
    FILE *fp;
    fp=fopen("array.txt","w");
    int i=0;
    for(i=0;i<50;i++)
    {
       a[i]=rand()%100+1;
       printf("%d\n",a[i]);
       fprintf(fp,"%d\n",a[i]);
    }
    fclose(fp);

    return 0;
}

