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
void numwork(PAInfo s[]);
void numpolitic(PAInfo s[]);
void numsex(PAInfo s[]);
void numedu(PAInfo s[]);
void numpost(PAInfo s[]);
int lenofbum(PAInfo s[], int k);
void DeleteInfo(PAInfo s[]);
void SearchName(PAInfo s[]);
void SearchNo(PAInfo s[]);
void Change(PAInfo s[]);
void SortAge(PAInfo s[]);
void menutj(PAInfo s[]);
void Sortstart_time(PAInfo s[]);
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
        case 7:
            Sortstart_time(st);
            break;
        case 8:
            SortAge(st);
            break;
        case 9:
            menutj(st);
            break;
        case 10:
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
    printf("7.按来院时间排序\n");
    printf("8.按年龄排序\n");
    printf("9.人员统计\n");
    printf("10.退出系统\n");

}
void menutj(PAInfo s[])
{
    int x;
    printf("请输入选项\n");
    printf("1.在职人数统计\n");
    printf("2.政治面貌统计\n");
    printf("3.性别统计\n");
    printf("4.学历统计\n");
    printf("5.职称统计\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        numwork(s);
        break;
    case 2:
        numpolitic(s);
        break;
    case 3:
        numsex(s);
        break;
    case 4:
        numedu(s);
        break;
    case 5:
        numpost(s);
        break;
    default:
        printf("输入错误,请重新选择\n");
        break;

    }
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
        printf("请输入性别(男1|女0)\n");
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
            printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
            printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
        if(strcmp(s[j].No,num)==0)
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
            case 1:
                printf("请输入编号\n");
                scanf("%s",s[j].No);
                break;
            case 2:
                printf("请输入姓名\n");
                scanf("%s",s[j].name);
                break;
            case 3:
                printf("请输入性别\n");
                scanf("%d",&s[j].sex);
                break;
            case 4:
                printf("请输入年龄\n");
                scanf("%d",&s[j].age);
                break;
            case 5:
                printf("请输职务\n");
                scanf("%s",s[j].job);
                break;
            case 6:
                printf("请输入职称\n");
                scanf("%s",s[j].post);
                break;
            case 7:
                printf("请输入政治面貌\n");
                scanf("%s",s[j].politic);
                break;
            case 8:
                printf("最高学历\n");
                scanf("%s",s[j].edu_level);
                break;
            case 9:
                printf("请输入任职时间\n");
                scanf("%s",s[j].period);
                break;
            case 10:
                printf("请输入来院时间\n");
                scanf("%s",s[j].start_time);
                break;
            default:
                printf("无变化\n");
                break;
            }
        }
    }
    for(j=0; j<i; j++)
    {
        fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[j].No,s[j].name,s[j].sex,s[j].age,s[j].job,s[j].post,s[j].politic,s[j].edu_level,s[j].period,s[j].start_time);
    }

    fclose(fp);
}
void SortAge(PAInfo s[])
{
    FILE  *fp;
    PAInfo temp;
    int i=0,j,n=0;
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        n++;
        i++;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(s[j].age<s[i].age)
            {
                temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
    printf("编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
    for(i=0; i<n; i++)
    {

        printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);

}
void Sortstart_time(PAInfo s[])
{
    FILE  *fp;
    PAInfo temp;
    int i=0,j,n=0;
    if((fp=fopen("personinfo.txt","r"))==NULL)
    {
        printf("Fail to open personinfo.txt.\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,&s[i].sex,&s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
        n++;
        i++;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(lenofbum(s,j)<lenofbum(s,i))
            {
                temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
    printf("编号 姓名 性别 年龄 职务 职称 政治面貌 最高学历 任职时间 来院时间\n");
    for(i=0; i<n; i++)
    {

        printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);

}
//计算数组中存放时间
int lenofbum(PAInfo s[], int k)
{
    int temp=0,i;
    for(i=0; i<strlen(s[k].start_time); i++)
        temp=temp*10+(s[k].start_time[i]-'0');
    return temp;
}

void numwork(PAInfo s[])
{
    FILE *fp;
    int i=0,k,ad=0;
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
    for(k=0; k<i; k++)
    {
        if(s[k].post[0]!='\0')ad++;

    }
    printf("在职人数%d\n",ad);
}
void numpolitic(PAInfo s[])
{
    FILE *fp;
    int i=0,k,ad=0;
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
    for(k=0; k<i; k++)
    {
        if(strcmp(s[k].politic,"dangyuan")==0)
        {
            ad++;
        }

    }
    printf("党员%d:\n",ad);
}
void numsex(PAInfo s[])
{
    FILE *fp;
    int i=0,k,ad=0;
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

    for(k=0; k<i; k++)
    {
        if(s[k].sex==0)
        {
            ad++;
        }


    }
    fclose(fp);
    printf("女工%d\n",ad);
}
void numedu(PAInfo s[])
{
    FILE *fp;
    int i=0,k,ad[3]= {0};
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
    for(k=0; k<i; k++)
    {
        if(strcmp(s[k].edu_level,"benke")==0)
        {
            ad[0]++;
        }
        else if(strcmp(s[k].edu_level,"shuoshi")==0)
        {
            ad[1]++;
        }
        else if(strcmp(s[k].edu_level,"boshi")==0)
        {
            ad[2]++;
        }

    }
    printf("本科%d 硕士%d 博士%d\n总人数%d\n",ad[0],ad[1],ad[2],ad[0]+ad[1]+ad[2]);
}
void numpost(PAInfo s[])
{
    FILE *fp;
    int i=0,k,ad[4]= {0};
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
    for(k=0; k<i; k++)
    {
        if(strcmp(s[k].post,"fujiaoshou")==0)
            ad[0]++;
        else if(strcmp(s[k].post,"jiaoshou")==0)
            ad[1]++;

    }
    printf("=副教授%d 教授%d\n总人数%d\n",ad[0],ad[1],ad[0]+ad[1]);

}




