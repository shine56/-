#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "All.h"
#define LIE 40         //���X
#define HANG 8      //���Y

int LEN=sizeof(account[0]);              //ע��ṹ��Ĵ�С
int LENStu=sizeof(StuIfor[0]);           //��¼ѧ����Ϣ�ṹ���С
int LENf=sizeof(feed[0]);                   //���������Ľṹ���С

int main()
{
    int a;                   //����ע�ᣬ��¼�����˳�
    system("color b0");
    while(1)
    {
        gotoxy(40, 5);                                //��ʼ����
        printf("ע�᡾0��  ��¼��1�� �˳�ϵͳ��2��");
        gotoxy(47, 7);
        printf("___________________");
        showLogin();                            //��¼����
        gotoxy(56, 7);
        scanf("%d", &a);
        if(a == 0)
        {
            system("cls");
            gotoxy(0,0);
            Signup();               //ǰ��ע��
            a=1;
        }
        if(a==1)
            a=Login(a);         //��¼�˺�
        if(a==2)
        {
            return 0;
        }
    }
}
void gotoxy(int x, int y)       //���ù��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void Signup()                    //ע���˺�
{
    int SignupN=0;                 //��¼�Ѿ�ע�������
    int b=0;                       //��������Ƿ���ȷ
    FILE *fp;
    if((fp=fopen("faccount.txt", "ab+")) == NULL)
    {
        printf("���ܴ��ļ�\n");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&account[SignupN], LEN, 1, fp)==1)
            SignupN++;
    }

    while(1)
    {
        if(b==1) break;

        ShowSignup();

        fflush(stdin);
        gotoxy(LIE+10, HANG-3);
        scanf("%c", &account[SignupN].Occ);           // ������ݣ� �˺������롣
        gotoxy(LIE+10, HANG+1);
        scanf("%s", account[SignupN].name);
        gotoxy(LIE+10, HANG+5);
        scanf("%s", account[SignupN].passward1);
        gotoxy(LIE+10, HANG+9);
        scanf("%s", account[SignupN].passward2);

        if(strcmp(account[SignupN].passward1, account[SignupN].passward2)!=0)
        {
            b=0;
            gotoxy(LIE, HANG+11);
            printf("������������벻һ��");
        }
        else{
                if(fwrite(&account[SignupN], LEN, 1, fp)!=1)        //д���ļ�
                {
                    printf("ע��ʧ�ܣ����ܱ���");
                    getch();
                }
                else{
                    b=1;
                    fclose(fp);         //�ر��ļ�

                    system("cls");
                    gotoxy(LIE+5, HANG+8);
                    printf(" ע���˺ųɹ���");
                    gotoxy(LIE+5, HANG+10);
                    printf("���������ǰ����¼");
                    fflush(stdin);
                    getchar();
                    return ;
                }
        }
    }
}
void ShowSignup()             //��ʾע�����
{
    gotoxy(LIE+9, HANG-4);
    printf("______________________");
    gotoxy(LIE, HANG-3);
    printf("   ���� ��                     �� ��ʦ(0)/ѧ��(1)");
    gotoxy(LIE+9, HANG-2);
    printf("����������������������");

    gotoxy(LIE+9, HANG);
    printf("______________________");
    gotoxy(LIE, HANG+1);
    printf("�û���  ��                     ��");
    gotoxy(LIE+9, HANG+2);
    printf("����������������������");

    gotoxy(LIE+9, HANG+4);
    printf("______________________");
    gotoxy(LIE, HANG+5);
    printf("  ����  ��                     ��");
    gotoxy(LIE+9, HANG+6);
    printf("����������������������");

    gotoxy(LIE+9, HANG+8);
    printf("______________________");
    gotoxy(LIE-6, HANG+9);
    printf("�ٴ���������  ��                     ��");
    gotoxy(LIE+9, HANG+10);
    printf("����������������������");

    gotoxy(LIE+11, HANG+13);
    printf("���س�ȷ��ע�᡿");
}
int Login(int a)                  //��¼����
{
    struct TemLogin        //��ʱ�ṹ��
    {
        char TemOcc;
        char Temname[20];
        char Tempassward[20];
    }temlogin;

    int m=0, i;                       //��¼�Ѿ�ע�������
    FILE *fp;
    if((fp=fopen("faccount.txt", "ab+"))==NULL)
    {
        printf("���ܴ��ļ�");
    }
    while(!feof(fp))
    {
        if(fread(&account[m], LEN, 1, fp)==1)
            m++;
    }
     fclose(fp);

    system("cls");
    showLogin();
    fflush(stdin);
    gotoxy(48, 11);
    scanf("%c", &temlogin.TemOcc);            // ������ݣ� �˺ţ�����
    gotoxy(48, 14);
    scanf("%s", temlogin.Temname);
    gotoxy(48, 17);
    scanf("%s", temlogin.Tempassward);

    int k=0;          //����Ƿ��¼�ɹ�
    for(i=0; i<m; i++)
    {
        if(strcmp(temlogin.Temname, account[i].name)==0)
        {
            if(temlogin.TemOcc==account[i].Occ)
            {
                if(strcmp(temlogin.Tempassward, account[i].passward1)==0)
                {
                    k=1;
                    if(temlogin.TemOcc=='1')
                        showStuMenu(i);
                    if(temlogin.TemOcc=='0')
                        showTeaMenu(i);
                    break;
                }
            }
        }
    }
    if(k==0)            //��½ʧ��
    {
        gotoxy(40, 25);
        printf(" �˺Ż��������");
        gotoxy(40, 26);
        printf("��y���ٴ�����   ��n���˳�ϵͳ");
        gotoxy(48, 27);
        printf("__________");
        gotoxy(53, 27);
        char ch=getch();
        if(ch=='y')
            a=1;
        else
            a=2;
    }
    system("cls");
    return a;
}
void showLogin()                //��ʾ��¼����
{
    gotoxy(44, 10);
    printf("   ____________________");
    gotoxy(40, 11);
    printf("���ǣ���                   ����ʦ(0)/ѧ��(1)");
    gotoxy(44, 12);
    printf("   ��������������������");
    gotoxy(44, 13);
    printf("   ____________________");
    gotoxy(40, 14);
    printf("�˺ţ���                   ��");
    gotoxy(44, 15);
    printf("   ��������������������");
    gotoxy(44, 16);
    printf("   ____________________");
    gotoxy(40, 17);
    printf("���룺��                   ��");
    gotoxy(44, 18);
    printf("   ��������������������");
    gotoxy(48, 22);
    printf("���س�ȷ�ϵ�¼��");
}
void showStuMenu(int flag)            //ѧ�����ܲ˵�
{
    while(1)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t��--------��--��--��--��--ϵ--ͳ---------��\n\n\n");
        printf("\t\t\t\t\tѧ  --------��1���鿴ѧ����Ϣ------------\n\n\n");
        printf("\t\t\t\t\t    --------��2������������Ϣ------------\n\n\n");
        printf("\t\t\t\t\t��  --------��3���޸ķ�����Ϣ------------\n\n\n");
        printf("\t\t\t\t\t    --------��4���޸��˺���Ϣ------------\n\n\n");
        printf("\t\t\t\t\t��  --------��0���˳���¼-----------------\n\n\n");
        printf("\t\t\t\t\t��--------ѧ---------��--------��--------��\n\n\n");

        int c, d;
        gotoxy(LIE+18, HANG*3+1);
        printf("��   ��");
        gotoxy(LIE+21, HANG*3+1);
        scanf("%d", &c);

        switch(c)
        {
        case 0:
            return ;
        case 1:
            Lookup();
            break;
        case 2:
            Feed();
            break;
        case 3:
            UpdateCon();
            break;
        case 4:
            d=UpdateAccount(flag);
            if(d==0)
                return ;
        }
    }
}
void showTeaMenu(int flag)            //��ʦ���ܲ˵�
{
    while(1)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t��--------��--��--��--��--ϵ--ͳ---------��\n\n");
        printf("\t\t\t\t\t    --------��1���鿴������Ϣ-----------\n\n");
        printf("\t\t\t\t\t��  --------��2���޸�ѧ����Ϣ-----------\n\n");
        printf("\t\t\t\t\t    --------��3������ѧ����Ϣ-----------\n\n");
        printf("\t\t\t\t\tʦ  --------��4��ɾ��ѧ����Ϣ-----------\n\n");
        printf("\t\t\t\t\t    --------��5��ѧ�������б�-----------\n\n");
        printf("\t\t\t\t\t��  --------��6���޸��˺���Ϣ-----------\n\n");
        printf("\t\t\t\t\t    --------��0���˳���¼----------------\n\n");
        printf("\t\t\t\t\t��--------��---------ʦ--------��--------��\n\n");

        int c;
        gotoxy(LIE+18, HANG*3+1);
        printf("��   ��");
        gotoxy(LIE+21, HANG*3+1);
        scanf("%d", &c);
        getchar();

        int d;               //�޸��˺���ϢҪ��
        switch(c)
        {
        case 0:
            return ;
            break;
        case 1 :
            Lookup();
            break;
        case 2 :
            Update();
            break;
        case 3 :
            AddStuIfor();
            break;
        case 4:
            DeleteStu();
            break;
        case 5:
            ShowFeedAllList();
            break;
        case 6:
            d=UpdateAccount(flag);
            if(d==0)
                return ;
        }
    }
}
void AddStuIfor()        //¼��ѧ����Ϣ
{
    FILE *fa;
    if((fa=fopen("Student Information.txt", "ab+")) == NULL)
    {
        printf("���ܴ��ļ���");
        return ;
    }

    int Num=0;    //��¼����ѧ������
    while(!feof(fa))
    {
        if(fread(&StuIfor[Num], LENStu, 1, fa) == 1)
        {
            Num++;
        }
    }

    system("cls");
    gotoxy(LIE, HANG);
    printf("��������Ҫ���ӵ�ѧ������Ϣ��");
    gotoxy(LIE, HANG+2);
    printf("ѧԺ��");
    gotoxy(LIE+4, HANG+3);
    printf("������������������������");
    gotoxy(LIE, HANG+4);
    printf("ѧ�ţ�");
    gotoxy(LIE+4, HANG+5);
    printf("������������������������");
    gotoxy(LIE, HANG+6);
    printf("������");
    gotoxy(LIE+4, HANG+7);
    printf("������������������������");
    gotoxy(LIE-2, HANG+8);
    printf("����ţ�                         (�磺6��316���6-316��)");
    gotoxy(LIE+4, HANG+9);
    printf("������������������������");
    gotoxy(LIE-4, HANG+10);
    printf("��ϵ�绰��");
    gotoxy(LIE+4, HANG+11);
    printf("������������������������");

    gotoxy(LIE+6, HANG+2);             //¼��ѧ����Ϣ
    scanf("%s", StuIfor[Num].college);
    gotoxy(LIE+6, HANG+4);
    scanf("%s", StuIfor[Num].Id);
    gotoxy(LIE+6, HANG+6);
    scanf("%s", StuIfor[Num].name);
    gotoxy(LIE+6, HANG+8);
    scanf("%s", StuIfor[Num].DorNum);
    gotoxy(LIE+6, HANG+10);
    scanf("%s", StuIfor[Num].PhoneN);

    if(fwrite(&StuIfor[Num], LENStu, 1, fa)!=1)        //д���ļ�
    {
        printf("¼��ѧ����Ϣʧ�ܣ����ܱ���");
        getchar();
    }
    else{
        fclose(fa);
        gotoxy(LIE+6, HANG+12);
        printf("¼��ѧ����Ϣ�ɹ�����������ء�");
        char g;
        g=getch();
    }
}
void Lookup()               //��ѯѧ����Ϣ
{
    int Num=0, i, j, FM=0;
    char ch1, TemId[20];
    FILE *fb;
    if((fb=fopen("Student Information.txt", "r")) == NULL)
    {
        printf("���ܴ��ļ���");
    }
    while(!feof(fb))
    {
        if(fread(&StuIfor[Num], LENStu, 1, fb) == 1)
        {
            Num++;
        }
    }
    fclose(fb);

    FILE *fx;
    if((fx=fopen("feedcontext.txt", "ab+")) == NULL)
    {
        printf("���ܴ򿪴��ļ���");
        getchar();
    }
    while(!feof(fx))
    {
        if(fread(&feed[FM], LENf, 1, fx) == 1)
            FM++;
    }
    fclose(fx);

    while(1)
    {
        system("cls");
        gotoxy(LIE, HANG);
        printf("���ҷ�ʽ��________ ��0����ѧ��/��1���������");
        gotoxy(LIE+14, HANG);
        scanf("%c", &ch1);

        char ch2='3';                    //�ж����޴���
        if(ch1=='0')                               //��ѧ�Ų������Ϣ
        {
            system("cls");
            gotoxy(LIE+9, HANG+2);
            printf("     ______________________");
            gotoxy(LIE, HANG+3);
            printf("��������ѧ�� ��                     ��");
            gotoxy(LIE+9, HANG+4);
            printf("     ����������������������");
            gotoxy(LIE+15, HANG+3);
            scanf("%s", TemId);

            for(i=0; i<Num; i++)
            {
                if(strcmp(StuIfor[i].Id, TemId) == 0)
                {
                    ShowStu(i);                     //��ʾ������Ϣ
                    printf("\t\t    ѧ����������Υ����Ϣ��\n");
                    //printf("%s**", StuIfor[i].DorNum);
                    Showfeedcontent(LIE-17, HANG+7, FM, StuIfor[i].DorNum);      //��ʾ���ᷴ����Ϣ
                    gotoxy(0, HANG+17);
                    printf("\t\t��--------------------------����ѧ����Ϣ����-------------------------------��\n");
                    printf("\t\t             ����1��������ѯ             ����0���˳�\n");
                    printf("\t\t                                 ��   ��");
                    gotoxy(LIE+12, HANG+19);
                    ch2=getch();
                    break;
                }
            }
            if(ch2=='3')
            {
                printf("\n\t\t\t\t\t���޴��ˣ�\n\n");
                printf("\t\t\t\t\t��1��������ѯ ��0�����ز˵�  ");
                ch2=getch();
            }
        }
        if(ch1=='1')                            //������Ų�����������Ϣ
        {
            system("cls");
            gotoxy(LIE+4, HANG-7);
            printf("________________");
            gotoxy(LIE-8, HANG-6);
            printf("��������� ��     x-xxx     �� ");
            gotoxy(LIE+3, HANG-5);
            printf(" ����������������");
            gotoxy(LIE+9, HANG-6);
            scanf("%s", TemId);                   //���������

            int a[4]; j=0;
            for(i=0; i<Num; i++)
            {
                if(strcmp(StuIfor[i].DorNum, TemId) == 0)
                {
                    a[j]=i;                                               //�ҵ������м�����
                    j++;
                }
            }
            if(j==0)
            {
                printf("\n\t\t\t\t�Ҳ������������Ϣ��\n\n");
                printf("\t\t\t\t��1��������ѯ ��0�����ز˵�  ");
                ch2=getch();
            }
            else{
                printf("\n��-----------------------------------------------����������Ϣ����------------------------------------------------��\n\n");
                for(i=0; i<j; i++)
                    printf("ѧԺ��      %-18s", StuIfor[a[i]].college);
                printf("\n\n");
                for(i=0; i<j; i++)
                    printf("ѧ�ţ�      %-18s", StuIfor[a[i]].Id);
                printf("\n\n");
                for(i=0; i<j; i++)
                    printf("������      %-18s", StuIfor[a[i]].name);
                printf("\n\n");
                for(i=0; i<j; i++)
                    printf("��ϵ�绰��  %-18s", StuIfor[a[i]].PhoneN);
                printf("\n\n");
                printf("�����ᱻ��������Ϣ��\n");
                Showfeedcontent(LIE-17, HANG+8, FM, TemId);           //��ʾ���ᷴ������Ϣ
                gotoxy(0, HANG+18);
                printf("\t\t             ����1��������ѯ             ����0���˳�\n");
                printf("\t\t                                ��   ��");

                gotoxy(LIE+11, HANG+19);
                ch2=getch();
            }
        }
        if(ch2=='0')       //������ѯ
        {
            break;
        }
    }

}
void  ShowStu(int i)        //��ʾѧ��������Ϣ
{
    system("cls");
    printf("\n");
    printf("\t\t��----------------------------��ѧ����Ϣ����-----------------------------��\n\n");
    printf("\t\t    ѧԺ��%s\n\n", StuIfor[i].college);
    printf("\t\t    ѧ�ţ�%s\n\n", StuIfor[i].Id);
    printf("\t\t    ������%s\n\n", StuIfor[i].name);
    printf("\t\t    ����ţ�%s\n\n", StuIfor[i].DorNum);
    printf("\t\t    ��ϵ�绰��%s\n\n", StuIfor[i].PhoneN);
}
void Update()                  //�޸�ѧ����Ϣ
{
    int Num=0, i, j=0;
    char Tem[20];
    FILE *fc;
    if((fc=fopen("Student Information.txt", "r+")) == NULL)
    {
        printf("���ܴ��ļ���");
    }
    while(!feof(fc))
    {
        if(fread(&StuIfor[Num], LENStu, 1, fc) == 1)
        Num++;
    }
    fclose(fc);
    system("cls");
    fflush(stdin);
    gotoxy(LIE+17, HANG+2);
    printf("     ______________________");
    gotoxy(LIE, HANG+3);
    printf("����Ҫ�޸ĵ�ѧ��ѧ�� ��                     ��");
    gotoxy(LIE+17, HANG+4);
    printf("     ����������������������");
    gotoxy(LIE+23, HANG+3);
    scanf("%s", Tem);

    char ch='6';            //�ж��Ƿ��д��˼������޸�����
    for(i=0; i<Num; i++)
    {
        if(strcmp(Tem, StuIfor[i].Id)==0)
        {
            j=i;
            ShowStu(i);
            printf("\t\t��----------------------------��ѧ����Ϣ����-----------------------------��\n\n");
            printf("\t\tѡ����Ҫ�޸ĵ�ѧ����Ϣ��______\n\n");
            printf("\t\t��1��ѧԺ  ��2��ѧ��  ��3������  ��4�������  ��5����ϵ�绰  ��0�����ز˵�\n");
            gotoxy(LIE+2, HANG+7);
            ch=getch();
            printf("%c", ch);
            gotoxy(0, HANG+12);
            printf("\t\t�����޸����ݣ�\n\n\n");
            printf("\t\t����������������������");
            switch(ch)
            {
            case '0':
                return;
            case '1':
                gotoxy(16, HANG+14);
                scanf("%s", StuIfor[i].college);
                break;
            case '2':
                gotoxy(16, HANG+14);
                scanf("%s", StuIfor[i].Id);
                break;
            case '3':
                gotoxy(16, HANG+14);
                scanf("%s", StuIfor[i].name);
                break;
            case '4':
                gotoxy(16, HANG+14);
                scanf("%s", StuIfor[i].DorNum);
                break;
            case '5':
                gotoxy(16, HANG+14);
                scanf("%s", StuIfor[i].PhoneN);
                break;
            }
            break;
        }
    }
    if(ch=='6')
        printf("\n\t\t\t\t\t���޴�ѧ�ţ�\n\n");
    else{
        if((fc=fopen("Student Information.txt", "w+")) == NULL)
        {
            printf("���ܴ��ļ���");
            getchar();
        }
        for(i=0; i<Num; i++)
        {
            if(fwrite(&StuIfor[i], LENStu, 1, fc)!=1)        //д���ļ�
            {
                printf("�޸�ѧ����Ϣʧ�ܣ����ܱ���");
                getchar();
            }
        }
        fclose(fc);

        gotoxy(0,0);
        ShowStu(j);
        printf("\t\t\t\t\t�޸ĳɹ���\n");
    }
    printf("\t\t\t\t\t������������ز˵�");
    ch=getch();
    return ;
}
void DeleteStu()               //ɾ��ѧ����Ϣ
{
    int Num=0, i, j;
    char Tem[20];
    FILE *fd;
    if((fd=fopen("Student Information.txt", "r+")) == NULL)
    {
        printf("���ܴ��ļ���");
        getchar();
    }
    while(!feof(fd))
    {
        if(fread(&StuIfor[Num], LENStu, 1, fd) == 1)
        Num++;
    }
    fclose(fd);                         //�ر��ļ�
    system("cls");
    fflush(stdin);
    gotoxy(LIE+17, HANG+2);
    printf("     ______________________");
    gotoxy(LIE, HANG+3);
    printf("����Ҫɾ����ѧ��ѧ�� ��                     ��");
    gotoxy(LIE+17, HANG+4);
    printf("     ����������������������");
    gotoxy(LIE+23, HANG+3);
    scanf("%s", Tem);

    char ch='2';            //�ж��Ƿ��д��˼������޸�����
    for(i=0; i<Num; i++)
    {
        if(strcmp(Tem, StuIfor[i].Id)==0)
        {
            j=i;
            ShowStu(j);
            printf("\t\t��----------------------------��ѧ����Ϣ����-----------------------------��\n\n");
            printf("\t\t\t\t��0�����ز˵�          ��1��ȷ��ɾ��\n\n");
            printf("\t\t\t\t\t       ��   ��");
            gotoxy(LIE+10, HANG+9);
            ch=getch();
            break;
        }
    }

    if(ch=='1')
    {
        if((fd=fopen("Student Information.txt", "w+")) == NULL)
        {
            printf("���ܴ��ļ���");
            getchar();
        }
        for(i=0; i<Num-1; i++)
        {
            if(i>=j)
                StuIfor[i]=StuIfor[i+1];
            if(fwrite(&StuIfor[i], LENStu, 1, fd)!=1)        //д���ļ�
            {
                printf("�޸�ѧ����Ϣʧ�ܣ����ܱ���");
                getchar();
            }
        }
        fclose(fd);
        system("cls");
        gotoxy(LIE, HANG);
        printf("ɾ���ɹ�������0�����ز˵���");
        ch=getch();
    }
    if(ch=='2')
    {
        gotoxy(LIE+10, HANG+11);
        printf("���޴��ˣ���������ز˵�");
        ch=getch();
    }
}
int UpdateAccount(int flag)      //�޸��˻���Ϣ
{
    char ch='3' ;//�д˴β����Ƿ��޸Ĺ��˺�
    while(1)
    {
        int SignupN=0, i;                 //��¼�Ѿ�ע�������
        FILE *fp;
        if((fp=fopen("faccount.txt", "r+")) == NULL)
        {
            printf("���ܴ��ļ�\n");
            getchar();
        }
        while(!feof(fp))
        {
            if(fread(&account[SignupN], LEN, 1, fp)==1)
                SignupN++;
        }
        fclose(fp);

        system("cls");
        gotoxy(LIE, HANG-7);
        if(ch=='1')
            printf("�޸ĳɹ���");
        gotoxy(LIE, HANG-6);
        printf("%s������˻���Ϣ���£�", account[flag].name);
        gotoxy(LIE+9, HANG-4);
        printf("______________________");
        gotoxy(LIE, HANG-3);
        printf("   ���� �� %c                   �� ��ʦ(0)/ѧ��(1)", account[flag].Occ);
        gotoxy(LIE+9, HANG-2);
        printf("����������������������");

        gotoxy(LIE+9, HANG);
        printf("______________________");
        gotoxy(LIE, HANG+1);
        printf("�û���  ��                     ��");
        gotoxy(LIE+9, HANG+2);
        printf("����������������������");
        gotoxy(LIE+10, HANG+1);
        printf("%s", account[flag].name);

        gotoxy(LIE+9, HANG+4);
        printf("______________________");
        gotoxy(LIE, HANG+5);
        printf("  ����  ��                     ��");
        gotoxy(LIE+10, HANG+5);
        printf("%s", account[flag].passward1);
        gotoxy(LIE+9, HANG+6);
        printf("����������������������\n\n");

         printf("\t\t\t\t\tѡ����Ҫ�޸ĵ�ѧ����Ϣ��______\n\n");
         printf("\t\t\t\t\t��1���˻���  ��2������  ��0�����ز˵�\n");
         gotoxy(LIE+27, HANG+8);
         ch=getch();

         if(ch=='1')
         {
             gotoxy(0, HANG+12);
             printf("\t\t\t\t\t�����µ��˻�����\n\n\n");
             printf("\t\t\t\t\t����������������������");
             gotoxy(LIE+1, HANG+14);
             scanf("%s", account[flag].name);
         }
         if(ch=='2')
         {
             gotoxy(0, HANG+12);
             printf("\t\t\t\t\t���������룺\n\n\n");
             printf("\t\t\t\t\t����������������������");
             gotoxy(LIE+1, HANG+14);
             scanf("%s", account[flag].passward1);
             gotoxy(0, HANG+16);
             printf("\t\t\t\t\t�ٴ����������룺\n\n\n");
             printf("\t\t\t\t\t����������������������");
             gotoxy(LIE+1, HANG+18);
             scanf("%s", account[flag].passward2);
         }
        if(ch=='0')
            return 1;

        if((fp=fopen("faccount.txt", "w+")) == NULL)
        {
            printf("���ܴ��ļ�\n");
            getchar();
        }
        for(i=0; i<SignupN; i++)
        {
          if(fwrite(&account[i], LEN, 1, fp)!=1)
          {
              printf("�޸�ʧ�ܣ��޷�д��");
              getchar();
          }
        }
        fclose(fp);

        if(ch=='2')
        {
            system("cls");
            gotoxy(LIE, HANG);
            printf("�޸ĳɹ�����������µ�¼");
            fflush(stdin);
            ch=getch();
            return 0;
        }
    }

}
void Feed()                            //ѧ��������Ϣ
{
    int FM=0;    //������Ϣ������
    FILE *fx;
    if((fx=fopen("feedcontext.txt", "ab+")) == NULL)
    {
        printf("���ܴ򿪴��ļ���");
        getchar();
    }
    while(!feof(fx))
    {
        if(fread(&feed[FM], LENf, 1, fx) == 1)
            FM++;
    }
    fclose(fx);

    system("cls");
    gotoxy(LIE+8, HANG-5);
    printf("______________________");
    gotoxy(LIE, HANG-4);
    printf("�����:��                     ��");
    gotoxy(LIE+8, HANG-3);
    printf("����������������������\n");
    gotoxy(LIE+9, HANG-4);
    scanf("%s", feed[FM].DorNum);          //��¼������Ϣ�������
   // printf("%s", feed[FM].DorNum);

    printf("\t��Ϣ������\n");
    printf("\t\t    |----------------------------------------------------------------------------------------|\n");
    printf("\t\t    |                                                                                        |\n");
    printf("\t\t    |                                                                                        |\n");
    printf("\t\t    |                                                                                        |\n");
    printf("\t\t    |----------------------------------------------------------------------------------------|\n\n");
    printf("\t\t             ����1��ȷ�Ϸ���             ����0���˳�\n");
    printf("\t\t                                ��   ��");

    gotoxy(LIE-19, HANG-1);
    scanf("%s", feed[FM].content);      //��������
    gotoxy(LIE+11, HANG+5);
    char ch=getch();

    time_t now;                    //������ʱ��
    struct tm *tmNow;
    time(&now);
    tmNow=localtime(&now);
    feed[FM].Y=tmNow->tm_year+1900;
    feed[FM].M=tmNow->tm_mon+1;
    feed[FM].D=tmNow->tm_mday;

    if(ch=='1')
    {
        if((fx=fopen("feedcontext.txt", "ab+")) == NULL)
        {
            printf("���ܴ򿪴��ļ���");
            getchar();
        }
        if(fwrite(&feed[FM], LENf, 1, fx)!=1)
        {
            printf("����ʧ�ܣ�����д�롣");
            getchar();
        }
        else{
            printf("\n\n\t\t\t\t�����ɹ�������������ز˵�");
            ch=getch();
        }
        fclose(fx);
    }
    return ;
}
void Showfeedcontent(int x, int y, int n, char *Dor)  //��ʾ���ᷴ����Ϣ
{
    printf("\t\t    |-------------------------------------------------------------------------------|\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |                                                                               |\n");
    printf("\t\t    |-------------------------------------------------------------------------------|\n\n");

    gotoxy(x-2, y);  int i, j, m, t=1;
    for(j=0; j<n; j++)
    {
        if(strcmp(Dor, feed[j].DorNum) == 0)
        {
            m=strlen(feed[j].content);
            printf("��%d��", t);     t++;            //���
            for(i=0; i<m; i++)
            {
                printf("%c", feed[j].content[i]);
                if(i==60)
                {
                    printf("\n");
                    gotoxy(x+3, ++y);
                }
            }
            printf("����%d.%d.%d\n", feed[j].Y, feed[j].M, feed[j].D);
            gotoxy(x-2, ++y);
        }
    }
}
void UpdateCon()                    //�޸ķ�����Ϣ
{
    int Num=0;
    char Tem[20];
    FILE *fy;
    if((fy=fopen("feedcontext.txt", "r+")) == NULL)
        printf("���ܴ��ļ���");
    while(!feof(fy))
    {
        if(fread(&feed[Num], LENf, 1, fy) == 1)
        Num++;
    }
    fclose(fy);
    system("cls");
    fflush(stdin);
    gotoxy(LIE+17, HANG-5);
    printf("     ______________________");
    gotoxy(LIE, HANG-4);
    printf("�����޸���Ϣ������� ��                     ��");
    gotoxy(LIE+17, HANG-3);
    printf("     ����������������������");
    gotoxy(LIE+23, HANG-4);
    scanf("%s", Tem);

    int mark[10], i, j=0;              //��¼������ķ�����Ϣ�������е�λ��
    for(i=0; i<Num; i++)
    {
        if(strcmp(Tem, feed[i].DorNum) == 0)
        {
            if(j==0)
            {
                printf("\n\t\t�����ᷴ����Ϣ���£�\n\n");
                Showfeedcontent(LIE-16, HANG+1, Num, Tem);
            }
            mark[j]=i;
            j++;
        }
    }

    gotoxy(0, HANG+11);
    printf("\t\tѡ��Ҫ�޸ĵ���Ϣ��ţ�_________\n\n\t\t");
    for(i=0; i<j; i++)
        printf("��%d��    ", i+1);
    gotoxy(LIE+2, HANG+11);
    fflush(stdin);
    char ch=getch();

    gotoxy(0, HANG+15);
    printf("\t\t�����޸����ݣ�\n\n\n");
    printf("\t\t����������������������������������������������������������������������������");
    gotoxy(LIE-24, HANG+17);
    scanf("%s", feed[mark[ch-'1']].content);

    time_t now;                    //�޸ĵ�ʱ��
    struct tm *tmNow;
    time(&now);
    tmNow=localtime(&now);
    feed[mark[ch-'1']].Y=tmNow->tm_year+1900;
    feed[mark[ch-'1']].M=tmNow->tm_mon+1;
    feed[mark[ch-'1']].D=tmNow->tm_mday;


    if((fy=fopen("feedcontext.txt", "w+")) == NULL)
    {
        printf("���ܴ��ļ���");
        getchar();
    }
    for(i=0; i<Num; i++)
    {
        if(fwrite(&feed[i], LENf, 1, fy)!=1)        //д���ļ�
        {
            printf("�޸�ѧ����Ϣʧ�ܣ����ܱ���");
            getchar();
        }
    }
    fclose(fy);

    gotoxy(LIE, HANG+19);        fflush(stdin);
    printf("�޸ĳɹ�����������ز˵�");
    ch=getch();
    return ;
}
void ShowFeedAllList()            //��ʾ����ѧ����Ϣ
{
    int FM=0;    //������Ϣ������
    FILE *fz;
    if((fz=fopen("feedcontext.txt", "ab+")) == NULL)
    {
        printf("���ܴ򿪴��ļ���");
        getchar();
    }
    while(!feof(fz))
    {
        if(fread(&feed[FM], LENf, 1, fz) == 1)
            FM++;
    }
    fclose(fz);

    system("cls");
    int i, j, x=23, y=4, c=1;
    printf("\n\tѧ����������Ϣ���£�");
    for(i=0; i<FM; i++)
    {
        for(j=i-1; j>-1; j--)
        {
            if(strcmp(feed[i].DorNum, feed[j].DorNum) == 0)
            {
                c=0;
                break;
            }
        }
        if(c==1)
        {
            gotoxy(x+33, y-2);
            printf("%s\n", feed[i].DorNum);
            Showfeedcontent(x, y, FM, feed[i].DorNum);
            printf("\n\n\n");
            y+=11;
        }
        c=1;
    }
    printf("\n\n\n\n\n\n\n\n\t\t");
    printf("��������ز˵�");
    char ch=getch();
    return;
}


