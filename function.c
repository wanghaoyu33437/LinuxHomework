#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int mkdirFile()
{
	FILE * f;
    char * file;
    file=malloc(sizeof(char)*15);
    printf("请输入文件名( 不超过15个字符 )：");
	getchar();
    gets(file);
    if( (f=fopen(file,"r")))
    {
        printf("文件已存在！\n");
    }
    else{
        f=fopen(file,"w");
        printf("创建成功！\n");
    }
    fclose(f);
    return 1;
}
int  wFile()
{
	FILE* f;
    char * file;
    char * content;
    char c;
    file=malloc(sizeof(char)*15);
    printf("请输入文件名( 不超过15个字符 )：");
	getchar();
    gets(file);
    while(!(f=fopen(file,"r")))
    {
            printf("当前文件不存在，是否重新输入文件名（Y/N）:");
            scanf(" %c" ,&c);
            if(c=='Y'||c=='y')
            {
                printf("请重新输入文件名( 不超过15个字符 )：");
                getchar();
                gets(file);
            }
            else{
                break;
            }
    }
    if(f)
    {
        printf("文件打开成功！\n");
        f=fopen(file,"a");
        printf("输入要写入文件内容：\n");
        content =malloc(sizeof(char)*100);
        gets(content);
        printf(content);
        fprintf(f,"%s",content);
    }
    fclose(f);
    free(content);
    free(file);
 	return 1;
}
int rFile()
{
	FILE* f;
    char * file;
    char * content;
    char c;
    file=malloc(sizeof(char)*15);
    printf("请输入文件名( 不超过15个字符 )：");
	getchar();
    gets(file);
    while(!(f=fopen(file,"r")))
    {
            printf("当前文件不存在，是否重新输入文件名（Y/N）:");
            scanf(" %c" ,&c);
            if(c=='Y'||c=='y')
            {
                printf("请重新输入文件名( 不超过15个字符 )：");
                getchar();
                gets(file);
            }
            else{
                break;
            }
    }
    if(f)
    {
        printf("文件内容：\n");
        content=malloc(sizeof(char)*100);
        fscanf(f,"%s",content);
        printf("%s",content);
    }
    fclose(f);
    free(content);
    free(file);
 	return 1;
}
int chmodFile()
{
	int choice;
     char * file;
    file=malloc(sizeof(char)*15);
    printf("请输入文件名( 不超过15个字符 )：");
    getchar();
    gets(file);
    printf("\n!************************************!\n");
    printf("修改当前文件权限：\n");
    printf("1. 用户所有者读、写、执行、\n");
    printf("2. 用户所有者读\n");
    printf("3. 用户所有者读写\n");
    printf("4. 用户所有者执行、\n");
    printf("5. 组所有者读、写、执行、\n");
    printf("6. 组所有者读\n");
    printf("7. 组所有者读写\n");
    printf("8. 组所有者执行、\n");
    printf("9. 其他所有者读、写、执行、\n");
    printf("10. 其他所有者读\n");
    printf("11. 其他所有者读写\n");
    printf("12. 其他所有者执行、\n");
    printf("!************************************!\n");
    printf("Please input your choice(0-6):");
	scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        if(chmod(file,S_IRWXU)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 2:
        if(chmod(file,S_IRUSR)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 3:
        if(chmod(file,S_IWUSR)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 4:
        if(chmod(file,S_IXUSR)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 5:
        if(chmod(file,S_IRWXG)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 6:
          if(chmod(file,S_IRGRP)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 7:
         if(chmod(file,S_IWGRP)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 8:
         if(chmod(file,S_IXGRP)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 9:
        if(chmod(file,S_IRWXO)<0)
            printf("chmod error!\n");
        else
            printf("chmod success\n");
        break;
    case 10:
        if(chmod(file,S_IROTH)<0)
            printf("chmod error!\n");
               else
            printf("chmod success\n");
        break;
    case 11:
         if(chmod(file,S_IWOTH)<0)
            printf("chmod error!\n");
               else
            printf("chmod success\n");
        break;
    case 12:
         if(chmod(file,S_IXOTH)<0)
            printf("chmod error!\n");
               else
            printf("chmod success\n");
        break;
    default:
        break;
    }

	return 0;
}
int showAndChomdFile()
{
	struct stat statbuf;
    char * file;
    file=malloc(sizeof(char)*15);
    printf("请输入文件名( 不超过15个字符 )：");
    getchar();
    gets(file);
    if(stat(file,&statbuf)<0)
        printf("无法获得%s文件的许可权!\n",file);

      if(access(file,F_OK)<0)
    {
        printf("文件不存在！\n");
    }
    else{
        printf("文件存在！\n");
          if(access(file,R_OK)<0)
    {
        printf("文件不可读！\n");
    }
    else{
        printf("文件可读！\n");
    }
    if(access(file,W_OK)<0)
    {
        printf("文件不可写！\n");
    }
    else{
        printf("文件可写！\n");
    }
    if(access(file,X_OK)<0)
    {
        printf("文件不可执行！\n");
    }
    else{
        printf("文件可执行！\n");
    }
    }
    return 0;
	return 0;
}
