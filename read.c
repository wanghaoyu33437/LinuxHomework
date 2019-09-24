#include <stdio.h>

int main()
{
    FILE * f;
    f=fopen("array.txt","r");
    int a;
    int i;
    for( i=0;i<50;i++)
    {
        fscanf(f,"%d\n",&a);
        printf("%d\n",a);
    }
    fclose(f);
}

