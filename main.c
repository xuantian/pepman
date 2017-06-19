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
    printf("7.����Ժʱ������\n");
    printf("8.����������\n");
    printf("9.��Աͳ��\n");
    printf("10.�˳�ϵͳ\n");

}
void menutj(PAInfo s[])
{
    int x;
    printf("������ѡ��\n");
    printf("1.��ְ����ͳ��\n");
    printf("2.������òͳ��\n");
    printf("3.�Ա�ͳ��\n");
    printf("4.ѧ��ͳ��\n");
    printf("5.ְ��ͳ��\n");
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
        printf("�������,������ѡ��\n");
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
        printf("�������Ա�(��1|Ů0)\n");
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
            printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
            printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
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
        if(strcmp(s[j].No,num)==0)
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
            case 1:
                printf("��������\n");
                scanf("%s",s[j].No);
                break;
            case 2:
                printf("����������\n");
                scanf("%s",s[j].name);
                break;
            case 3:
                printf("�������Ա�\n");
                scanf("%d",&s[j].sex);
                break;
            case 4:
                printf("����������\n");
                scanf("%d",&s[j].age);
                break;
            case 5:
                printf("����ְ��\n");
                scanf("%s",s[j].job);
                break;
            case 6:
                printf("������ְ��\n");
                scanf("%s",s[j].post);
                break;
            case 7:
                printf("������������ò\n");
                scanf("%s",s[j].politic);
                break;
            case 8:
                printf("���ѧ��\n");
                scanf("%s",s[j].edu_level);
                break;
            case 9:
                printf("��������ְʱ��\n");
                scanf("%s",s[j].period);
                break;
            case 10:
                printf("��������Ժʱ��\n");
                scanf("%s",s[j].start_time);
                break;
            default:
                printf("�ޱ仯\n");
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
    printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
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
    printf("��� ���� �Ա� ���� ְ�� ְ�� ������ò ���ѧ�� ��ְʱ�� ��Ժʱ��\n");
    for(i=0; i<n; i++)
    {

        printf("%s %s %d %d %s %s %s %s %s %s\n",s[i].No,s[i].name,s[i].sex,s[i].age,s[i].job,s[i].post,s[i].politic,s[i].edu_level,s[i].period,s[i].start_time);
    }
    fclose(fp);

}
//���������д��ʱ��
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
    printf("��ְ����%d\n",ad);
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
    printf("��Ա%d:\n",ad);
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
    printf("Ů��%d\n",ad);
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
    printf("����%d ˶ʿ%d ��ʿ%d\n������%d\n",ad[0],ad[1],ad[2],ad[0]+ad[1]+ad[2]);
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
    printf("=������%d ����%d\n������%d\n",ad[0],ad[1],ad[0]+ad[1]);

}




