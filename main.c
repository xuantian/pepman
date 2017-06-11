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
    printf("6.�����޸�\n");
    printf("7.����\n");
    printf("8.��Աͳ��\n");
    printf("9.�˳�ϵͳ\n");

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
        printf("��������\n");
        scanf("%s",s[i].No);
        printf("����������\n");
        scanf("%s",s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        printf("����ְ��\n");
        scanf("%s",s[i].job);
        printf("������ְ��\n");
        scanf("%s",s[i].post);
        printf("������������ò\n");
        scanf("%s",s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",s[i].period);
        printf("��������Ժʱ��\n");
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
        printf("��������\n");
        scanf("%s",s[i].No);
        printf("����������\n");
        scanf("%s",s[i].name);
        printf("�������Ա�\n");
        scanf("%d",&s[i].sex);
        printf("����������\n");
        scanf("%d",&s[i].age);
        printf("����ְ��\n");
        scanf("%s",s[i].job);
        printf("������ְ��\n");
        scanf("%s",s[i].post);
        printf("������������ò\n");
        scanf("%s",s[i].politic);
        printf("���ѧ��\n");
        scanf("%s",s[i].edu_level);
        printf("��������ְʱ��\n");
        scanf("%s",s[i].period);
        printf("��������Ժʱ��\n");
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
    printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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
    printf("�������ѯ����\n");
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
            printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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


}
void SearchNo(PAInfo s[])
{

    FILE *fp;
    char z[10];
    int k=0,i=0,n=0;
    printf("�������ѯ���\n");
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
            printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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

}
void DeleteInfo(PAInfo s[])
{
    FILE  *fp;
    int i=0,j=0;
    char num[10];

    printf("����ɾ���˵ı�ţ�\n");
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
        printf("ɾ���ɹ�\n");
        }
    }

    fclose(fp);
}
void Change(PAInfo s[])
{
    FILE  *fp;
    int i=0,j,x;
    char num[10];
    printf("���뱻�޸��˵ı�ţ�\n");
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
            printf("��ѡ��ı�ѡ��\n");
            printf("1.�޸ı��\n");
            printf("2.�޸�����\n");
            printf("3.�޸��Ա�\n");
            printf("4.�޸�����\n");
            printf("5.�޸�ְ��\n");
            printf("6.�޸�ְ��\n");
            printf("7.�޸�������ò\n");
            printf("8.�޸����ѧ��\n");
            printf("9.�޸���ְʱ��\n");
            printf("10�޸���Ժʱ��\n");
            scanf("%d",&x);
            switch(x)
            {
            case 1:printf("��������\n");
        scanf("%s",s[i].No);break;
                case 2:printf("����������\n");
        scanf("%s",s[i].name);break;
                case 3:printf("�������Ա�\n");
        scanf("%d",&s[i].sex);break;
                case 4:printf("����������\n");
        scanf("%d",&s[i].age);break;
                case 5:printf("����ְ��\n");
        scanf("%s",s[i].job);break;
                case 6:printf("������ְ��\n");
        scanf("%s",s[i].post);break;
                case 7:printf("������������ò\n");
        scanf("%s",s[i].politic);break;
                case 8:printf("���ѧ��\n");
        scanf("%s",s[i].edu_level);break;
                case 9: printf("��������ְʱ��\n");
        scanf("%s",s[i].period);break;
                case 10:printf("��������Ժʱ��\n");
        scanf("%s",s[i].start_time);break;
                default:printf("�ޱ仯\n");break;
            }
            fprintf(fp,"%s %s %d %d %s %s %s %s %s %s\n",s[j].No,s[j].name,s[j].sex,s[j].age,s[j].job,s[j].post,s[j].politic,s[j].edu_level,s[j].period,s[j].start_time);
        }
    }
    fclose(fp);
}

