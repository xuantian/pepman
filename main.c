#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
/*
1����������ģ��
   ��Ա����Ϣд�����µ����ļ���
��2���������ģ��
   ��׷�ӵķ�ʽ������Ա����Ϣд�����µ����ļ���
��3������ɾ��ģ��
������Ա��Ų���Ҫɾ������Ա�����ļ��ж�һ����¼���鿴����Ƿ�Ҫɾ��������ǣ�������������д���ļ�����������д���ļ���
��4�����ݲ�ѯģ��
     �ѱ�ź�������Ϊ��ѯ�ֶΣ��û��������㷨�������µ����ļ����ѷ��ϲ���Ҫ��ļ�¼�����
��5�������޸�ģ��
    ����Ҫ�޸ĵļ�¼���޸�֮���ȶ���¼������Ҫ�޸ĵļ�¼�����޸���Ϣ�����޸ĺ����Ϣд���ļ�������ֱ��д���ļ���
��6����������ģ��
    ͨ���˵�ѡ�����������Ժʱ�䣬�����ݴ��ļ��ж�����������ѡ��һ�������㷨�Լ�¼�������������������
��7������ͳ��ģ��
ͨ���˵�ѡ��ͳ���ֶΣ���ְ��������Ա������Ů����������ѧ����������ְ��������
����ѡ��Ա��������ͳ������α�����£�
Count=0;    //��¼��ְ����
While���ļ�δ���꣩
{
   ��һ����¼��
   If(������ò�ǵ�Ա)
   {
      Count++;
    ���������¼��
}
�����ֶε�ͳ������������ơ�
*/

typedef struct personnelArchiveInfo
{
    char No[10];       //���
    char name[10];     //����
    int sex;           //�Ա�
    int age;           //����
    char job[10];      //ְ��
    char post[10];     //ְ��
    char  politic[10];    //������ò
    char edu_level[10];  //���ѧ��
    char period[10];    //��ְʱ��
    char  start_time[10];  //��Ժʱ��
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
    printf("�������¹���ϵͳ�ɹ���\n");
    while(1)
    {
        menu();
        printf("������ѡ��\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf("������¼������\n");
            scanf("%d",&n);
            InputRecord(st,n);
            break;
        case 2:
            printf("��������������\n");
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
            printf("�������,������ѡ��\n");
            break;
        }
    }
}
void menu()
{
    printf("1.Ա����Ϣ����\n");
    printf("2.Ա����Ϣ���\n");
    printf("3.Ա����Ϣɾ��\n");
    printf("4.����Ų�����Ϣ\n");
    printf("5.������������Ϣ\n");
    printf("5.�����޸�\n");
    printf("6.����\n");
    printf("7.��Աͳ��\n");
    printf("8.�˳�ϵͳ\n");

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
    fprintf(fp,"��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
    for(i=0; i<n; i++)
    {
        printf("��������\n");
        scanf("%s",&s[i].No);
        printf("����������\n");
        scanf("%s",&s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        printf("����ְ��\n");
        scanf("%s",&s[i].job);
        printf("������ְ��\n");
        scanf("%s",&s[i].post);
        printf("������������ò\n");
        scanf("%s",&s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",&s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",&s[i].period);
        printf("��������Ժʱ��\n");
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
        printf("��������\n");
        scanf("%s",&s[i].No);
        printf("����������\n");
        scanf("%s",&s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        printf("����ְ��\n");
        scanf("%s",&s[i].job);
        printf("������ְ��\n");
        scanf("%s",&s[i].post);
        printf("������������ò\n");
        scanf("%s",&s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",&s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",&s[i].period);
        printf("��������Ժʱ��\n");
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
    printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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
    printf("�������ѯ����\n");
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
            printf("\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
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
        printf("����Ϣ\n");
    }
    fclose(fp);

}
void SearchNo(PAInfo s[])
{

    FILE *fp;
    char z[10];
    int k=0,i,n;
    printf("�������ѯ���\n");
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
            printf("\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
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
        printf("����Ϣ\n");
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
    printf("��Ҫɾ�����˵�������\n");
    scanf("%d",&number);
    for(i=0; i<number; i++)
    {
        printf("����ɾ���˵���Ϣ�ı�ź�������\n");
        printf("����ɾ���˵ı�ţ�\n");
        scanf("%d",&a[i]);
        printf("����ɾ���˵�������\n");
        scanf("%s",b[i]);
        printf("���ղ�������˵���Ϣ�ı�ź�������\n");
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
    printf("������ĺ�������Ա����Ϣ��\n��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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
