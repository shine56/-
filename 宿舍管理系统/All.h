void showLogin();                         //��ʾ��½����
void showStuMenu(int flag);             //��ʾѧ�����ܲ˵�
void showTeaMenu(int flag);               //��ʦ���ܲ˵�
void ShowSignup();                        //��ʾע�����
void ShowStu(int i);                         //��ʾѧ��������Ϣ
void Showfeedcontent(int x, int y, int n, char *Dor); //�鿴���˷�����Ϣ
void ShowFeedAllList();                                    //�鿴�����˷�����Ϣ

void gotoxy(int x, int y);                   //���ù��
void Signup();                               //ע���˺�  ������ʦѧ��
int Login(int a);                               //��¼�˺�
void AddStuIfor();                            //����ѧ����Ϣ
void Lookup();                                //�鿴ѧ����Ϣ
void Update();                                //�޸�ѧ����Ϣ
void DeleteStu();                             //ɾ��������Ϣ
int UpdateAccount(int flag);              //�޸ĸ�����Ϣ
void Feed();                                   //ѧ��������Ϣ
void UpdateCon();                                           //�޸ķ�����Ϣ


struct Account                                               //ע���˺ŵĽṹ������
{
    char Occ;                       //���
    char name[20];                //�û���
    char passward1[20];         //����
    char passward2[20];        //�ٴ���������
}account[100];

struct Infor
{
    char college[25];           //ѧԺ
    char Id[20];                 //ѧ��
    char name[10];             //����
    char DorNum[10];         //���Һ���
    char PhoneN[20];          //��ϵ�绰
}StuIfor[1000];

struct Feed
{
    char DorNum[10];       //�����
    char content[1000];      //��������
    int Y;                        //����ʱ�䣬 ������
    int M;
    int D;
} feed[1000];

/*��д��һ����ʦ����ɾ��ѧ���˺ţ� ���ֺ�ǰ��ɾ��ѧ����Ϣ����������˼·����һ��
����ûɶ��Ҫ�� ����д��һ��Ͳ�д��*/
/*void DelStuAcc()
{
    char ch='3';
    while(1)
    {
        int SignupN=0, i, j=-1;                 //��¼�Ѿ�ע�������
        char Temacc[20];
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
        gotoxy(LIE, HANG-8);
        if(ch!='3')
            printf("ɾ���ɹ���");
        gotoxy(LIE, HANG-7);
        printf("����Ҫɾ��ѧ�����û�����");
        gotoxy(LIE+20, HANG-6);
        printf("������������������")
        gotoxy(LIE+20, HANG-5);
        scanf("%s", Temacc);

        for(i=0; i<SignupN; i++)
        {
            if(strcmp(Temacc, account[i].name)==0)
            {
                j=i;
                break;
            }
        }
        if(j!=1)
        {
            gotoxy(LIE, HANG-3);
            printf("_________")
            gotoxy(LIE, HANG-1);
            printf("��1��ȷ��ɾ��       ��0��ȡ��")
        }
    }
}*/


