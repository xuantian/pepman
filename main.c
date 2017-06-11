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
void DeleteInfo(PAInfo s[]);
void SearchName(PAInfo s[]);
void SearchNo(PAInfo s[]);
void ReadFp(PAInfo s[]);
void ListRead(PAInfo s[],int n);
void Change(PAInfo s[]);
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
            DeleteInfo(st);
            break;
        case 4:
            SearchNo(st);
            break;

        case 5:
            SearchName(st);
            break;
        case 6:
            Change(st);
            break;
        case 9:
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
    printf("6.数据修改\n");
    printf("7.排序\n");
    printf("8.人员统计\n");
    printf("9.退出系统\n");

}
void InputRecord(PAInfo s[], int n)
{
    FILE *fp;
    int i;
    if((fp=fopen("personinfo.txt","w"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }

    for(i=0; i<n; i++)
    {
        printf("请输入编号\n");
        scanf("%s",s[i].No);
        printf("请输入姓名\n");
        scanf("%s",s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        printf("请输职务\n");
        scanf("%s",s[i].job);
        printf("请输入职称\n");
        scanf("%s",s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",s[i].politic);
        printf("最高学历\n");
        scanf("%s",s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",s[i].start_time);
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);
}
void AddRecord(PAInfo s[], int n)
{
    FILE *fp;
    int i;
    if((fp=fopen("personinfo.txt","a"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    for(i=0; i<n; i++)
    {
        printf("请输入编号\n");
        scanf("%s",s[i].No);
        printf("请输入姓名\n");
        scanf("%s",s[i].name);
        printf("请输入性别\n");
        scanf("%d",&s[i].sex);
        printf("请输入年龄\n");
        scanf("%d",&s[i].age);
        printf("请输职务\n");
        scanf("%s",s[i].job);
        printf("请输入职称\n");
        scanf("%s",s[i].post);
        printf("请输入政治面貌\n");
        scanf("%s",s[i].politic);
        printf("最高学历\n");
        scanf("%s",s[i].edu_level);
        printf("请输入任职时间\n");
        scanf("%s",s[i].period);
        printf("请输入来院时间\n");
        scanf("%s",s[i].start_time);
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);
}
void ReadFp(PAInfo s[])
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
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
    int i=0,n=0,k=0;
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
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        i++;
        k++;
    }
    fclose(fp);
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].name)==0)
        {
            printf("编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
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


}
void SearchNo(PAInfo s[])
{

    FILE *fp;
    char z[10];
    int k=0,i=0,n=0;
    printf("请输入查询编号\n");
    scanf("%s",z);
    if((fp=fopen("personinfo.txt","r+"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        i++;
        k++;
    }
    fclose(fp);
    for(i=0; i<k; i++)
    {
        if(strcmp(z,s[i].No)==0)
        {
            printf("编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
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

}
void DeleteInfo(PAInfo s[])
{
    FILE  *fp;
    int i=0,j=0;
    char num[10];

    printf("输入删除人的编号：\n");
    scanf("%s",num);
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        i++;
    }
    fclose(fp);
    if((fp=fopen("personinfo.txt","w"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    for(j=0; j<i; j++)
    {
        if(strcmp(s[j].No,num)!=0)
        {
            fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[j].No,s[j].name,s[j].sex,s[j].age,s[j].job,s[j].post,s[j].politic,s[j].edu_level,s[j].period,s[j].start_time);
        printf("删除成功\n");
        }
    }

    fclose(fp);
}
void Change(PAInfo s[])
{
    FILE  *fp;
    int i=0,j,x;
    char num[10];
    printf("输入被修改人的编号：\n");
    scanf("%s",num);
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        i++;
    }
    fclose(fp);
    if((fp=fopen("personinfo.txt","w"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    for(j=0; j<i; j++)
    {
        if(strcmp(s[j].No,num)!=0)
        {
            fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[j].No,s[j].name,s[j].sex,s[j].age,s[j].job,s[j].post,s[j].politic,s[j].edu_level,s[j].period,s[j].start_time);
        }
        else
        {
            printf("请选择改变选项\n");
            printf("1.修改编号\n");
            printf("2.修改姓名\n");
            printf("3.修改性别\n");
            printf("4.修改年龄\n");
            printf("5.修改职务\n");
            printf("6.修改职称\n");
            printf("7.修改政治面貌\n");
            printf("8.修改最高学历\n");
            printf("9.修改任职时间\n");
            printf("10修改来院时间\n");
            scanf("%d",&x);
            switch(x)
            {
            case 1:printf("请输入编号\n");
        scanf("%s",s[i].No);break;
                case 2:printf("请输入姓名\n");
        scanf("%s",s[i].name);break;
                case 3:printf("请输入性别\n");
        scanf("%d",&s[i].sex);break;
                case 4:printf("请输入年龄\n");
        scanf("%d",&s[i].age);break;
                case 5:printf("请输职务\n");
        scanf("%s",s[i].job);break;
                case 6:printf("请输入职称\n");
        scanf("%s",s[i].post);break;
                case 7:printf("请输入政治面貌\n");
        scanf("%s",s[i].politic);break;
                case 8:printf("最高学历\n");
        scanf("%s",s[i].edu_level);break;
                case 9: printf("请输入任职时间\n");
        scanf("%s",s[i].period);break;
                case 10:printf("请输入来院时间\n");
        scanf("%s",s[i].start_time);break;
                default:printf("无变化\n");break;
            }
            fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[j].No,s[j].name,s[j].sex,s[j].age,s[j].job,s[j].post,s[j].politic,s[j].edu_level,s[j].period,s[j].start_time);
        }
    }
    fclose(fp);
}

