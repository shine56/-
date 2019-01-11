#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define _X 35                               //���x
#define _Y 5                                //���y

//�����¼�ṹ��
typedef struct AbRecord{
    int Y;                                          //ȱ������,��
    int M;                                         //��
    int D;                                         //��
    char LNum[20];                             //ȱ�ν���
    char LName[50];                            //�γ�����
    char StuName[25];                         //ѧ������
    int  Type;                                    //ȱ�����ͣ��ٵ������ˣ����Σ����
    struct AbRecord *next;                   //ָ����һ���ڵ��ָ��
}Record;
int LEN = sizeof(struct AbRecord);         //�ṹ���С

void AddStu(Record *head);                                                 //¼��ѧ��ȱ����Ϣ
void ChangeStu(Record *head);                                            //�޸�ѧ��ȱ����Ϣ
void LookupStu(Record *head);                                            //����ĳ��ѧ��ȱ�μ�¼
void DeleteStu(Record *head);                                              //ɾ��ĳ����Ϣ
void CountStuRecord(Record suit[100], int m);                         //ͳ��ĳ��ʱ����ε�ѧ��
void CountClassRecord(Record suit[100], int m);                       //ͳ��ĳ��ʱ����ѧ�����εĿγ�
void gotoxy(int x, int y);                                                     //���ù��
void ShowRecord(Record *p);                                               //��ʾ��¼
Record* Fread();                                                               //���ļ���Ϣд������
void Fwrite(Record* head);                                                 //������д���ļ�
void SuitTime(Record *head, char ch);                                  //��������ʱ��εļ�¼
int main()
{
    //��������ļ�
    FILE *fp;
    if((fp = fopen("record.txt", "a")) == NULL)
        printf("�����ļ�ʧ��");
    fclose(fp);

    while(1)
    {
        system("cls");
        system("color F0");
        printf("\n\n\n\n");
        printf("\t\t\t\t\t��------��-------ӭ------ʹ------��------��\n\n");
        printf("\t\t\t\t\t    --------��1��¼��ȱ����Ϣ-----------\n\n");
        printf("\t\t\t\t\t    --------��2���޸�ȱ����Ϣ-----------\n\n");
        printf("\t\t\t\t\t    --------��3����ѯȱ�μ�¼-----------\n\n");
        printf("\t\t\t\t\t    --------��4��ɾ��ȱ�μ�¼-----------\n\n");
        printf("\t\t\t\t\t    --------��5��ѧ��ȱ�����-----------\n\n");
        printf("\t\t\t\t\t    --------��6���γ�ȱ�����-----------\n\n");
        printf("\t\t\t\t\t    --------��0���˳�ϵͳ----------------\n\n");
        printf("\t\t\t\t\t��--------��--��--��--��--ϵ--ͳ---------��\n\n\n");
        printf("\t\t\t\t\t\t\t��   ��");

        //��ȡ�û�ѡ��
        gotoxy(_X+24, _Y+18);
        fflush(stdin);
        char ch = getch();

        Record *head = Fread();            //��ȡ��ͷ
        switch(ch)
        {
        case '0':
            return 0;
        case '1' :
            AddStu(head);
            break;
        case '2' :
            ChangeStu(head);
            break;
        case '3' :
            LookupStu(head);
            break;
        case '4' :
            DeleteStu(head);
            break;
        case '5':
            SuitTime(head, ch);
            break;
        case '6':
            SuitTime(head, ch);
            break;
        }
    }
    return 0;
}
//���ù��
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);        //��ȡ��굱ǰλ��
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);                                 //���ù��λ��
}
//���ļ�����д������
Record* Fread()
{
    Record *head =NULL, *last, *p;

    FILE *fa;
    if((fa = fopen("record.txt", "r")) == NULL)
        printf("�����ļ�ʧ��");
    while(!feof(fa))
    {
        if((p = (Record*)malloc(LEN)) == NULL)
            printf("�����ڴ����");

        if(fread(p, LEN, 1, fa) == 1)
        {
            if(head == NULL)
            {
                head = p;
                last = p;
            }
            else{
                last->next = p;
                last = p;
                last->next = NULL;
            }
        }
    }
    fclose(fa);
    return head;
}
//���ݴ���
void Fwrite(Record* head)
{
    Record *p;

    FILE *fb;
    if((fb = fopen("record.txt", "w")) == NULL)
        printf("�����ļ�ʧ��");
    for(p=head; p; p=p->next)
    {
        if(fwrite(p, LEN, 1, fb) != 1)
            printf("д���ļ�����");
    }
    fclose(fb);
}
//¼��ѧ��ȱ�μ�¼
void AddStu(Record *head)
{
    while(1)
    {
        char ch1;                                                        //ȷ���Ƿ����ѭ��
        system("cls");
        printf("\n\t\t\t\t\t\t¼��ѧ��ȱ����Ϣ");
        printf("\n\n\n\t\t\t\tѧ��������");
        printf("\n\t\t\t\t\t ��������������������");
        printf("\n\n\t\t\t\tȱ�����ڣ�     ��      ��      ��   ");
        printf("\n\t\t\t\t\t ������  ������  ������");
        printf("\n\n\t\t\t\tȱ�νڴΣ�                   ���磺���߰˽ڣ�");
        printf("\n\t\t\t\t\t ��������������������");
        printf("\n\n\t\t\t\t��Ŀ���ƣ�                   ���磺��װ������   ");
        printf("\n\t\t\t\t\t ��������������������");
        printf("\n\n\t\t\t\tȱ�����ͣ�    ��   ��");
        printf("\n\t\t\t\t\t ��������������������");
        printf("\n\n\t\t\t\t��1���ٵ�   ��2������   ��3������   ��4�����");
        printf("\n\n\t\t\t\t                  ��   ��");
        printf("\n\n\t\t\t\t��0��ȡ��¼�뷵�ز˵�    ����������ȷ��¼��");

       //************************************����ȱ����Ϣ***************************
        Record *p = (Record*)malloc(LEN), *q = head;             //����һ���½ڵ�
        gotoxy(_X+7, _Y-1);  scanf("%s", p->StuName);             //����
        gotoxy(_X+7, _Y+2);  scanf("%d", &p->Y);                    //��
        while(1)
        {
            gotoxy(_X+16, _Y+2);  scanf("%d", &p->M);              //��
            if(p->M>0 && p->M<13)
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t                  ");
                break;
            }
            else{
                printf("\t\t\t\t\t\t\t\t\t\t\t�·���������");
                gotoxy(_X+16, _Y+2);  printf("    ");
            }
        }
        while(1)
        {
            gotoxy(_X+24, _Y+2);  scanf("%d", &p->D);               //��
            if(p->D>0 && p->D<32)
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t                  ");
                break;
            }
            else
            {
                printf("\t\t\t\t\t\t\t\t\t\t\t�շ���������");
                gotoxy(_X+24, _Y+2);   printf("    ");
            }

        }
        gotoxy(_X+7, _Y+5);  scanf("%s", p->LNum);                //�γ̽ڴ�
        gotoxy(_X+7, _Y+8);  scanf("%s", p->LName);               //�γ�����
        while(1)
        {
            gotoxy(_X+14, _Y+11);  char typee = getch();          //ѡ��ȱ������
            gotoxy(_X+14, _Y+11);  printf("%c", typee);
            p->Type = typee - '0';
            if(p->Type>0 && p->Type<5)
                break;
            else
                printf("\n\t\t\t\tѡ�����������ѡ��");
        }
        p->next = NULL;

        gotoxy(_X+18, _Y+16); char ch=getch();                 //ȷ���Ƿ�¼��

        if(ch!='0')
        {
            if(head == NULL)
                head = p;
            else{
                while(q->next)                                             //�ҵ���β
                {
                    q = q->next;
                }
                q->next = p;
                q=p;                                                        //�����½ڵ�
                q->next = NULL;
            }
                Fwrite(head);
                system("cls");
                ShowRecord(p);
                printf("\n\t\t\t\t��Ϣ¼��ɹ�........��1������¼����Ϣ   ��������ز˵�");
                gotoxy(_X+18, _Y+16); ch1 = getch();
        }
        if(ch1 != '1')                                                        //ȷ���Ƿ����ѭ��
            return;
    }
}
//�޸�ѧ��ȱ�μ�¼
void ChangeStu(Record *head)
{
    char ch1;                                           //ȷ���Ƿ��޸�
    char stuName[25];
    system("cls");
    printf("\n\t\t\t\t\t\t�޸�ѧ��ȱ����Ϣ");
    printf("\n\n\t\t\t\t����ѧ��������");
    printf("\n\t\t\t\t\t     ��������������������");
    gotoxy(_X+11, _Y-2);     scanf("%s", stuName);

    Record *q;
    int num=0,  count=0;                          //��ѧ��ȱ�μ�¼�ж�����

    for(q=head; q; q=q->next)
        if(strcmp(q->StuName, stuName) == 0)
        {
            num++;
            printf("\n\t\t\t\t******************��%d��******************", num);
            ShowRecord(q);
        }
    if(num>0)
    {
        printf("\n\t\t\t\t������Ҫ�޸ĸ�ѧ��ȱ�����Σ�");
         char No = getch();
         for(q=head; q; q = q->next)                       //����Ŀ������
        {
            if(strcmp(q->StuName, stuName) == 0)
            {
                count++;
                if(count == No-'0')
                {
                    system("cls");
                    printf("\n\t\t\t\t��ѧ����Ϣ���£�");
                    ShowRecord(q);
                    printf("\n\t\t\t\tѡ��Ҫ�޸ĵ���Ϣ  ��   ��");
                    printf("\n\n\t��1��ѧ������ ��2��ȱ������ ��3��ȱ�νڴ� ��4����Ŀ���� ��5��ȱ������ ��0�����ز˵�");
                    gotoxy(_X+18, _Y+13); char ch = getch();                                //ѡ���޸ĵ���Ŀ
                    gotoxy(_X+18, _Y+13);  printf("%c", ch);

                    //*********************�����޸ĵ���Ϣ*********************

                    switch(ch)
                    {
                    case '0':
                        return;
                    case '1' :
                        printf("\n\n\n\n\t\t\t\t����ѧ��������");
                        printf("\n\t\t\t\t\t    ��������������������");
                        gotoxy(_X+10, _Y+17);  scanf("%s", q->StuName);
                        break;
                    case '2' :
                        printf("\n\n\n\n\t\t\t\tȱ�����ڣ�     ��      ��      ��   ");
                        printf("\n\t\t\t\t\t ������  ������  ������");
                        gotoxy(_X+7, _Y+17);  scanf("%d", &q->Y);
                        gotoxy(_X+15, _Y+17);  scanf("%d", &q->M);
                        gotoxy(_X+23, _Y+17);  scanf("%d", &q->D);
                        break;
                    case '3' :
                        printf("\n\n\n\n\t\t\t\tȱ�νڴΣ�                   ���磺���߰˽ڣ�");
                        printf("\n\t\t\t\t\t ��������������������");
                        gotoxy(_X+6, _Y+17);  scanf("%s", q->LNum);
                        break;
                    case '4' :
                        printf("\n\n\n\n\t\t\t\tȱ�����ƣ�                   ���磺��װ������   ");
                        printf("\n\t\t\t\t\t ��������������������");
                        gotoxy(_X+6, _Y+17);  scanf("%s", q->LName);
                        break;
                    case '5' :
                        printf("\n\n\n\n\t\t\t\tȱ�����ͣ�    ��   ��");
                        printf("\n\n\t\t\t\t��1���ٵ�   ��2������   ��3������   ��4�����");
                        while(1)
                        {
                            gotoxy(_X+14, _Y+17);  char typee = getch();          //ѡ��ȱ�����
                            gotoxy(_X+14, _Y+17);  printf("%c", typee);
                            q->Type = typee - '0';
                            if(q->Type>0 && q->Type<5)
                                break;
                            else
                                printf("\n\t\t\t\tѡ�����������ѡ��");
                        }
                    }
                    system("cls");
                    printf("\n\n\t\t\t\t�޸ĺ���Ϣ���£�");
                    ShowRecord(q);
                    printf("\n\n\t\t\t\t���������ȷ�� ��0��ȡ�������ز˵�........ ");
                    gotoxy(_X+38, _Y+15);  ch1 = getch();                   //ȷ���޸�
                    break;
                }
            }
        }
    }
    else{                                                                            //�޸�ѧ���ļ�¼
        printf("\n\t\t\t\t\t��ѧ����%d��ȱ�μ�¼", num);
        printf("\n\n\t\t\t\t��������������ز˵�........ ");
        getch();
    }

    if(ch1 != '0')
    {
        Fwrite(head);
    }
    return;
}
//��ʾ��¼
void ShowRecord(Record *p)
{
    printf("\n\n\n\t\t\t\tѧ��������%s", p->StuName);
    printf("\n\t\t\t\t\t ��������������������");
    printf("\n\n\t\t\t\tȱ�����ڣ�%d  ��  %d  ��  %d ��   ", p->Y, p->M, p->D);
    printf("\n\t\t\t\t\t ������  ������  ������");
    printf("\n\n\t\t\t\tȱ�νڴΣ�%s ", p->LNum);
    printf("\n\t\t\t\t\t ��������������������");
    printf("\n\n\t\t\t\tȱ�����ƣ�%s ", p->LName);
    printf("\n\t\t\t\t\t ��������������������");
    char *s;
    if(p->Type == 1)
        s = "�ٵ�";
    if(p->Type == 2)
        s = "����";
    if(p->Type == 3)
        s = "����";
    if(p->Type == 4)
        s = "���";
    printf("\n\n\t\t\t\tȱ�����ͣ�%s", s);
    printf("\n\t\t\t\t\t ��������������������");
    return;
}
//��ѯѧ����¼
void LookupStu(Record *head)
{
    while(1)
    {
        char stuName[25];
        system("cls");
        printf("\n\t\t\t\t\t\t��ѯѧ��ȱ����Ϣ");
        printf("\n\n\t\t\t\t����ѧ��������");
        printf("\n\t\t\t\t\t     ��������������������");
        gotoxy(_X+11, _Y-2);     scanf("%s", stuName);

        int key =0 ;              //������޴���
        Record *q;
        for(q=head; q; q = q->next)                       //����Ŀ������
        {
            if(strcmp(q->StuName, stuName) == 0)
            {
                key++;
                printf("\n\t\t\t\t***************************��%d��****************************", key);
                ShowRecord(q);
            }
        }
        printf("\n\t\t\t\t*********************************************************************");
        if(key == 0)
            printf("\n\t\t\t\t�Ҳ�����ѧ��ȱ�μ�¼");
        printf("\n\n\t\t\t\t���������������ѯ ��0�����ز˵�");
        printf("\n\n\t\t\t\t........");
        char ch = getch();
        if(ch == '0')
            return;
    }
}
//ɾ��ѧ����¼
void DeleteStu(Record *head)
{
    char ch1;                                           //ȷ���Ƿ�ɾ��
    char stuName[25];
    system("cls");
    printf("\n\t\t\t\t\t\t�޸�ѧ��ȱ����Ϣ");
    printf("\n\n\t\t\t\t����ѧ��������");
    printf("\n\t\t\t\t\t     ��������������������");
    gotoxy(_X+11, _Y-2);     scanf("%s", stuName);

    Record *q, *p;
    int num=0,  count=0;                          //��ѧ��ȱ�μ�¼�ж�����

    for(q=head; q; q=q->next)
        if(strcmp(q->StuName, stuName) == 0)
        {
            num++;
            printf("\n\t\t\t\t******************��%d��******************", num);   //�ҵ���¼�����
            ShowRecord(q);
        }
    if(num>0)
    {
        printf("\n\t\t\t\t������Ҫ�޸ĸ�ѧ��ȱ�����Σ�");
         char No = getch();
         for(q=head; q; q = q->next)                       //����Ŀ������
        {
            if(strcmp(q->StuName, stuName) == 0)
            {
                count++;
                if(count == No-'0')                              //�ҵ��ýڵ�
                {
                    system("cls");
                    ShowRecord(q);
                    printf("\n\t\t\t\t��0��ȡ�������ز˵� ,������ȷ��ɾ��........");
                    ch1 = getch();
                    if(q == head)                                 //Ҫɾ���ڵ���ͷ
                    {
                        printf("*******************ͷ");
                         head = q->next;
                        free(q);
                        break;
                    }
                    if(q->next == NULL)                        //Ҫɾ���ڵ���β
                    {
                        printf("***************β��");
                        p->next =NULL;
                        free(q);
                        break;
                    }
                    p->next = q->next;
                    free(q);
                    break;
                }
            }
            p = q;
        }
        if(ch1!='0')
        {
            Fwrite(head);                                               //�����޸ĺ������ļ�
            printf("\n\t\t\t\tɾ���ɹ�! ���������..........");
            getch();
        }
    }
    else{
        printf("\n\t\t\t\t\t��ѧ����%d��ȱ�μ�¼", num);     //û�ҵ�Ҫɾ������Ϣ
        printf("\n\n\t\t\t\t��������������ز˵�........ ");
        getch();
    }
}
//ͳ��ĳ��ʱ����ε�ѧ��,
void SuitTime(Record *head, char ch)
{
    //�����������
    int y1, y2, m1, m2, d1, d2;
    system("cls");
    printf("\n�������������");
    printf("\n\n      ��       ��     ��->");
    printf("\n������  ������  ������");
    printf("\n      ��      ��      ��");
    printf("\n������  ������  ������");
    gotoxy(_X-34, _Y-2);  scanf("%d", &y1);
    gotoxy(_X-24, _Y-2);  scanf("%d", &m1);
    gotoxy(_X-16, _Y-2);  scanf("%d", &d1);
    gotoxy(_X-34, _Y);  scanf("%d", &y2);
    gotoxy(_X-24, _Y);  scanf("%d", &m2);
    gotoxy(_X-16, _Y);  scanf("%d", &d2);

    //���ҷ��������Ľڵ㲢�����
    Record *p, suit[100];
    int m = 0;
    for(p=head; p; p=p->next)
    {
        if(p->Type == 3)                                          //���ε�ѧ��
        {
            if(p->Y < y1 || p->Y>y2)                           //�������������
                continue;
            else{
                if( (p->M<m1 && p->Y==y1) || (p->M>y2 && p->Y==y2))     //�������·�����
                    continue;
                else{
                    if( (p->M==m1 && p->Y==y1 && p->D<d1)|| (p->M==y2 && p->Y==y2 && p->D>d2))  //ͬ��ͬ���շֲ�����
                        continue;
                    else{
                        suit[m].Y=p->Y;  suit[m].M=p->M; suit[m].D=p->D;
                        strcpy(suit[m].StuName, p->StuName);
                        strcpy(suit[m].LName, p->LName);
                        strcpy(suit[m].LNum, p->LNum);
                        suit[m].Type=p->Type;
                        m++;
                       // printf("***%s", suit[0].StuName);
                    }
                }
            }
        }
    }
    if(ch == '5')
        CountStuRecord(suit, m);
    if(ch == '6')
        CountClassRecord(suit, m);
}
//����ѧ�����δ�������
void CountStuRecord(Record suit[100], int m)
{
    int i, j, a[100]={0}, sum;
    for(i=0; i<m; i++)
    {
        sum=1;
        if(suit[i].Type != 0)                                 //δ��ͳ�ƹ�������
        {
            for(j=i+1; j<m; j++)                            //ͳ�����ֳ��ֵĴ���
                if(strcmp(suit[i].StuName, suit[j].StuName) == 0)
                {
                    sum++;
                     suit[j].Type = 0;
                }
            a[i] = sum;
        }
    }
    int t;   Record tt;
    for(i=0; i<m; i++)
    {
        if(a[i]!=0)
        {
            for(j=i+1; j<m; j++)
            {
                if(a[i]<a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;

                    tt = suit[i];
                    suit[i] = suit[j];
                    suit[j] = tt;
                }
            }
        }
    }

    gotoxy(0, 0);
    printf("\n\t\t\t\t\t**********************************");
    printf("\n\t\t\t\t\t*  ����               ���δ���  *");
    printf("\n\t\t\t\t\t**********************************");
    for(i=0; i<m; i++)
    {
        if(a[i]!=0)
        {
            printf("\n\n\t\t\t                   %-15s         %-5d", suit[i].StuName, a[i]);
            printf("\n\t\t\t\t\t**********************************");
        }
    }
    printf("\n\n\t\t\t\t��������ز˵�..........");
    getch();
}
//���տ�Ŀ�����˴�����
void CountClassRecord(Record suit[100], int m)
{
    int i, j, a[100]={0}, sum;
    for(i=0; i<m; i++)
    {
        sum=1;
        if(suit[i].Type != 0)                                 //δ��ͳ�ƹ��Ŀ�Ŀ
        {
            for(j=i+1; j<m; j++)                            //ͳ�ƿ�Ŀ���ֵĴ���
                if(strcmp(suit[i].LName, suit[j].LName) == 0)
                {
                    sum++;
                     suit[j].Type = 0;
                }
            a[i] = sum;
        }
    }
    int t;   Record tt;
    for(i=0; i<m; i++)
    {
        if(a[i]!=0)
        {
            for(j=i+1; j<m; j++)
            {
                if(a[i]<a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;

                    tt = suit[i];
                    suit[i] = suit[j];
                    suit[j] = tt;
                }
            }
        }
    }

    gotoxy(0, 0);
    printf("\n\t\t\t\t\t  **********************************");
    printf("\n\t\t\t\t\t  *   ��Ŀ               ��������  *");
    printf("\n\t\t\t\t\t  **********************************");
    for(i=0; i<m; i++)
    {
        if(a[i]!=0)
        {
            printf("\n\n\t\t\t                    %-15s         %-5d", suit[i].LName, a[i]);
            printf("\n\t\t\t\t\t  **********************************");
        }
    }
    printf("\n\n\t\t\t\t\t\t��������ز˵�..........");
    getch();
}
