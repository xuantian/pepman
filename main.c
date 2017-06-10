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
void DeleteInfo();
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
        case 3:
            DeleteInfo();
            break;
        case 4:
            SearchNo(st);
            break;

        case 5:
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
    fprintf(fp,"编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
    for(i=0; i<n; i++)
    {
        printf("请输入编号\n");
        scanf("%s",&s[i].No);
        printf("请输入姓名\n");
        scanf("%s",&s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        printf("请输职务\n");
        scanf("%s",&s[i].job);
        printf("请输入职称\n");
        scanf("%s",&s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",&s[i].politic);
        printf("最高学历\n");
        scanf("%s",&s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",&s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",&s[i].start_time);
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
        printf("请输入姓名\n");
        scanf("%s",&s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        printf("请输职务\n");
        scanf("%s",&s[i].job);
        printf("请输入职称\n");
        scanf("%s",&s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",&s[i].politic);
        printf("最高学历\n");
        scanf("%s",&s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",&s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",&s[i].start_time);
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);
}
int ReadFp(PAInfo s[])
{
    FILE *fp;
    int i=0;
    if((fp=fopen("personinfo.txt","a"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",&s[i].No,&s[i].name,&s[i].sex,&s[i].age,&s[i].job,&s[i].post,&s[i].politic,&s[i].edu_level,&s[i].period,&s[i].start_time);
        i++;
    }
    fclose(fp);
}
void ListRead(PAInfo s[],int n)
{
    int i;
    printf("编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
    for(i=0; i<n; i++)
    {
        printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }

}
void SearchName(PAInfo s[])
{

    FILE *fp;
    int k=0,i,n;
    char z[10];
    printf("请输入查询姓名\n");
    scanf("%s",z);
    if((fp=fopen("personinfo.txt","r+"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",&s[i].No,&s[i].name,&s[i].sex,&s[i].age,&s[i].job,&s[i].post,&s[i].politic,&s[i].edu_level,&s[i].period,&s[i].start_time);
        k++;
    }
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].No)==0)
        {
            printf("\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
            printf("%s\t",s[i].No);
            printf("%s\t",s[i].name);
            printf("%d\t",s[i].sex);
            printf("%d\t",s[i].age);
            printf("%s\t",s[i].job);
            printf("%s\t",s[i].post);
            printf("%s\t",s[i].politic);
            printf("%s\t",s[i].edu_level);
            printf("%s\t",s[i].period);
            printf("%s\t",s[i].start_time);
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
    if((fp=fopen("personinfo.txt","r+"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        getch();
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",&s[i].No,&s[i].name,&s[i].sex,&s[i].age,&s[i].job,&s[i].post,&s[i].politic,&s[i].edu_level,&s[i].period,&s[i].start_time);
        k++;
    }
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].No)==0)
        {
            printf("\t编号\t\t姓名\t\t性别\t\t年龄\t\t职务\t\t职称\t\t政治面貌\t最高学历\t任职时间\t来院时间\n");
            printf("%s\t",s[i].No);
            printf("%s\t",s[i].name);
            printf("%d\t",s[i].sex);
            printf("%d\t",s[i].age);
            printf("%s\t",s[i].job);
            printf("%s\t",s[i].post);
            printf("%s\t",s[i].politic);
            printf("%s\t",s[i].edu_level);
            printf("%s\t",s[i].period);
            printf("%s\t",s[i].start_time);
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
void DeleteInfo()
{
    FILE *fp,*fp1;
    int i,number,k,j,m;
    PAInfo s1[N],s2[N];
    int a[N];
    char b[N][10];
    printf("您要删除的人的人数：\n");
    scanf("%d",&number);
    for(i=0; i<number; i++)
    {
        printf("输入删除人的信息的编号和姓名：\n");
        printf("输入删除人的编号：\n");
        scanf("%d",&a[i]);
        printf("输入删除人的姓名：\n");
        scanf("%s",b[i]);
        printf("您刚才输入的人的信息的编号和姓名：\n");
        printf("%d  %s\n",a[i],b[i]);
    }
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        getch();
        exit(0);
    }
    for(i=0; !feof(fp); i++)
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",&s2[i].No,&s2[i].name,&s2[i].sex,&s2[i].age,&s2[i].job,&s2[i].post,&s2[i].politic,&s2[i].edu_level,&s2[i].period,&s2[i].start_time);
    k=i;
    m=0;
    for(i=0; i<k; i++)
    {
        for(j=0; j<number; j++)
        {
            if(s2[i].No==a[j]||!strcmp(s2[i].name,b[j]))break;
        }
        if(j==number)s1[m]=s2[i],m++;
    }
    printf("输出更改后所有人员的信息：\n编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
    if((fp1=fopen("personinfo.txt","w"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        getch();
        exit(0);
    }
    for(i=0; i<m; i++)
    {
        printf("%s %s %d %d %s %s %s %s %s %s\n",s1[i].No,s1[i].name,s1[i].sex,s1[i].age,s1[i].job,s1[i].post,s1[i].politic,s1[i].edu_level,s1[i].period,s1[i].start_time);
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s1[i].No,s1[i].name,s1[i].sex,s1[i].age,s1[i].job,s1[i].post,s1[i].politic,s1[i].edu_level,s1[i].period,s1[i].start_time);
    }
    fclose(fp1);
    getch();
}
