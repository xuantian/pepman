#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
/*
1）数据输入模块
   把员工信息写入人事档案文件。
（2）数据添加模块
   用追加的方式把新增员工信息写入人事档案文件。
（3）数据删除模块
根据人员编号查找要删除的人员，从文件中读一条记录，查看编号是否要删除，如果是，则舍弃，不再写入文件；否则重新写入文件。
（4）数据查询模块
     把编号和姓名作为查询字段，用基本查找算法查找人事档案文件，把符合查找要求的记录输出。
（5）数据修改模块
    查找要修改的记录，修改之。先读记录，若是要修改的记录，则修改信息，把修改后的信息写入文件；否则直接写入文件。
（6）数据排序模块
    通过菜单选择年龄或者来院时间，把数据从文件中读出来，任意选择一种排序算法对记录进行排序，输出排序结果。
（7）数据统计模块
通过菜单选择统计字段：在职人数、党员人数、女工人数、高学历人数、高职称人数。
例如选择党员人数，则统计运算伪码如下：
Count=0;    //记录在职人数
While（文件未读完）
{
   读一条记录；
   If(政治面貌是党员)
   {
      Count++;
    输出该条记录；
}
其他字段的统计运算与次类似。
*/

typedef struct personnelArchiveInfo
{
    char No[10];       //编号
    char name[10];     //姓名
    int sex;           //性别
    int age;           //年龄
    char job[10];      //职务
    char post[10];     //职称
    char  politic[10];    //政治面貌
    char edu_level[10];  //最高学历
    char period[10];    //任职时间
    char  start_time[10];  //来院时间
} PAInfo;
void menu();
void InputRecord(PAInfo s[], int n);
void AddRecord(PAInfo s[], int n);
void SearchName(PAInfo s[]);
void SearchNo(PAInfo s[]);
int ReadFp(PAInfo s[]);
void ListRead(PAInfo s[],int n);
int main()
{
    PAInfo st[N];
    int x,n;
    printf("进入人事管理系统成功！\n");
    while(1)
    {
        menu();
        printf("请输入选项\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf("请输入录入人数\n");
            scanf("%d",&n);
            InputRecord(st,n);
            break;
        case 2:
            printf("请输入增加人数\n");
            scanf("%d",&n);
            AddRecord(st,n);
            break;
        case 4:
            printf("\n");
            SearchNo(st);
            break;

        case 5:
            printf("\n");
            SearchName(st);
            break;

        case 8:
            exit(0);
            break;
        default:
            printf("输入错误,请重新选择\n");
            break;
        }
    }
}
void menu()
{
    printf("1.员工信息输入\n");
    printf("2.员工信息添加\n");
    printf("3.员工信息删除\n");
    printf("4.按编号查找信息\n");
    printf("5.按姓名查找信息\n");
    printf("5.数据修改\n");
    printf("6.排序\n");
    printf("7.人员统计\n");
    printf("8.退出系统\n");

}
void InputRecord(PAInfo s[], int n)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("personinfo.txt","w"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    fprintf(fp,"\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
    for(i=0; i<n; i++)
    {
        printf("请输入编号\n");
        scanf("%s",&s[i].No);
        fprintf(fp,"%10s\t",s[i].No);
        printf("请输入姓名\n");
        scanf("%s",&s[i].name);
        fprintf(fp,"%10s\t",s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        fprintf(fp,"%10d\t",s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        fprintf(fp,"%10d\t",s[i].age);
        printf("请输职务\n");
        scanf("%s",&s[i].job);
        fprintf(fp,"%10s\t",s[i].job);
        printf("请输入职称\n");
        scanf("%s",&s[i].post);
        fprintf(fp,"%10s\t",s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",&s[i].politic);
        fprintf(fp,"%10s\t",s[i].politic);
        printf("最高学历\n");
        scanf("%s",&s[i].edu_level);
        fprintf(fp,"%10s\t",s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",&s[i].period);
        fprintf(fp,"%10s\t",s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",&s[i].start_time);
        fprintf(fp,"%10s\t",s[i].start_time);
        fprintf(fp,"\n");
    }
    fclose(fp);
}
void AddRecord(PAInfo s[], int n)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("personinfo.txt","a"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    for(i=0; i<n; i++)
    {
        printf("请输入编号\n");
        scanf("%s",&s[i].No);
        fprintf(fp,"%10s\t",s[i].No);
        printf("请输入姓名\n");
        scanf("%s",&s[i].name);
        fprintf(fp,"%10s\t",s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        fprintf(fp,"%10d\t",s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        fprintf(fp,"%10d\t",s[i].age);
        printf("请输职务\n");
        scanf("%s",&s[i].job);
        fprintf(fp,"%10s\t",s[i].job);
        printf("请输入职称\n");
        scanf("%s",&s[i].post);
        fprintf(fp,"%10s\t",s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",&s[i].politic);
        fprintf(fp,"%10s\t",s[i].politic);
        printf("最高学历\n");
        scanf("%s",&s[i].edu_level);
        fprintf(fp,"%10s\t",s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",&s[i].period);
        fprintf(fp,"%10s\t",s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",&s[i].start_time);
        fprintf(fp,"%10s\t",s[i].start_time);
        fprintf(fp,"\n");
    }
    fclose(fp);
}
int ReadFp(PAInfo s[])
{
    FILE *fp;
    int k=0;
    if((fp=fopen("personinfo.txt","a"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",&s[k].No);
        fscanf(fp,"%s",&s[k].name);
        fscanf(fp,"%d",&s[k].sex);
        fscanf(fp,"%d",&s[k].age);
        fscanf(fp,"%s",&s[k].job);
        fscanf(fp,"%s",&s[k].post);
        fscanf(fp,"%s",&s[k].politic);
        fscanf(fp,"%s",&s[k].edu_level);
        fscanf(fp,"%s",&s[k].period);
        fscanf(fp,"%s",&s[k].start_time);
        k++;
    }
    fclose(fp);
}
void ListRead(PAInfo s[],int n)
{
    int i;
    printf("\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
    for(i=0; i<n; i++)
    {
        printf("%10s\t",s[i].No);
        printf("%10s\t",s[i].name);
        printf("%10d\t",s[i].sex);
        printf("%10d\t",s[i].age);
        printf("%10s\t",s[i].job);
        printf("%10s\t",s[i].post);
        printf("%10s\t",s[i].politic);
        printf("%10s\t",s[i].edu_level);
        printf("%10s\t",s[i].period);
        printf("%10s\t",s[i].start_time);
        printf("\n");
    }
}
void SearchName(PAInfo s[])
{

    FILE *fp;
    int k=0,i,n;
    char z[10];
    printf("请输入查询姓名\n");
    scanf("%s",z);
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",&s[k].No);
        fscanf(fp,"%s",&s[k].name);
        fscanf(fp,"%d",&s[k].sex);
        fscanf(fp,"%d",&s[k].age);
        fscanf(fp,"%s",&s[k].job);
        fscanf(fp,"%s",&s[k].post);
        fscanf(fp,"%s",&s[k].politic);
        fscanf(fp,"%s",&s[k].edu_level);
        fscanf(fp,"%s",&s[k].period);
        fscanf(fp,"%s",&s[k].start_time);
        k++;
    }
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].No)==0)
        {
            printf("\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
            printf("%10s\t",s[i].No);
            printf("%10s\t",s[i].name);
            printf("%10d\t",s[i].sex);
            printf("%10d\t",s[i].age);
            printf("%10s\t",s[i].job);
            printf("%10s\t",s[i].post);
            printf("%10s\t",s[i].politic);
            printf("%10s\t",s[i].edu_level);
            printf("%10s\t",s[i].period);
            printf("%10s\t",s[i].start_time);
            printf("\n");
            n++;
        }
    }
    if(n==0)
    {
        printf("无信息\n");
    }
    fclose(fp);

}
void SearchNo(PAInfo s[])
{


    FILE *fp;
    char z[10];
    int k=0,i,n;
    printf("请输入查询编号\n");
    scanf("%s",z);
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",&s[k].No);
        fscanf(fp,"%s",&s[k].name);
        fscanf(fp,"%d",&s[k].sex);
        fscanf(fp,"%d",&s[k].age);
        fscanf(fp,"%s",&s[k].job);
        fscanf(fp,"%s",&s[k].post);
        fscanf(fp,"%s",&s[k].politic);
        fscanf(fp,"%s",&s[k].edu_level);
        fscanf(fp,"%s",&s[k].period);
        fscanf(fp,"%s",&s[k].start_time);
        k++;
    }
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].No)==0)
        {
            printf("\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
            printf("%10s\t",s[i].No);
            printf("%10s\t",s[i].name);
            printf("%10d\t",s[i].sex);
            printf("%10d\t",s[i].age);
            printf("%10s\t",s[i].job);
            printf("%10s\t",s[i].post);
            printf("%10s\t",s[i].politic);
            printf("%10s\t",s[i].edu_level);
            printf("%10s\t",s[i].period);
            printf("%10s\t",s[i].start_time);
            printf("\n");
            n++;
        }
    }
    if(n==0)
    {
        printf("无信息\n");
    }
    fclose(fp);
}
