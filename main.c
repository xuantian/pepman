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
    fprintf(fp,"\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
    for(i=0; i<n; i++)
    {
        printf("��������\n");
        scanf("%s",&s[i].No);
        fprintf(fp,"%10s\t",s[i].No);
        printf("����������\n");
        scanf("%s",&s[i].name);
        fprintf(fp,"%10s\t",s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        fprintf(fp,"%10d\t",s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        fprintf(fp,"%10d\t",s[i].age);
        printf("����ְ��\n");
        scanf("%s",&s[i].job);
        fprintf(fp,"%10s\t",s[i].job);
        printf("������ְ��\n");
        scanf("%s",&s[i].post);
        fprintf(fp,"%10s\t",s[i].post);
        printf("������������ò\n");
        scanf("%s",&s[i].politic);
        fprintf(fp,"%10s\t",s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",&s[i].edu_level);
        fprintf(fp,"%10s\t",s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",&s[i].period);
        fprintf(fp,"%10s\t",s[i].period);
        printf("��������Ժʱ��\n");
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
        printf("��������\n");
        scanf("%s",&s[i].No);
        fprintf(fp,"%10s\t",s[i].No);
        printf("����������\n");
        scanf("%s",&s[i].name);
        fprintf(fp,"%10s\t",s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        fprintf(fp,"%10d\t",s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        fprintf(fp,"%10d\t",s[i].age);
        printf("����ְ��\n");
        scanf("%s",&s[i].job);
        fprintf(fp,"%10s\t",s[i].job);
        printf("������ְ��\n");
        scanf("%s",&s[i].post);
        fprintf(fp,"%10s\t",s[i].post);
        printf("������������ò\n");
        scanf("%s",&s[i].politic);
        fprintf(fp,"%10s\t",s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",&s[i].edu_level);
        fprintf(fp,"%10s\t",s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",&s[i].period);
        fprintf(fp,"%10s\t",s[i].period);
        printf("��������Ժʱ��\n");
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
    printf("\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
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
    printf("�������ѯ����\n");
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
            printf("\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
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
            printf("\t���\t\t����\t\t�Ա�\t\t����\t\tְ��\t\tְ��\t\t������ò\t���ѧ��\t��ְʱ��\t��Ժʱ��\n");
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
        printf("����Ϣ\n");
    }
    fclose(fp);
}
