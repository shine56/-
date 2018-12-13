#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

#define H 30
#define K 59
int V=300;   //Ĭ���ٶ� 
int score=0, ko=-6, foodsum=0;   //���� , ko����score��nλ����n���ո�  foodsum��¼�Ե���ʳ������ 
int a[H][K];

void gamestart(int (*a)[K]);         //��Ϸ��ʼ�� 
void show(int (*a)[K]);             // ������ʾ 
void gameplay(int (*a)[K]);         // ��Ϸ���� 
void Smove(char move, int (*a)[K]); //�ߵ��ƶ� 
void gotoxy(int x, int y);           //���꺯��
void food(int (*a)[K]); 			//����ʳ�� 	
void changevelocity();     		//�ı��ٶ� 
void gameover();               //��Ϸ���� 
void show2(int m);               //�ٶ�ѡ����� 


int main()
{
	
	gamestart(a); 
	changevelocity(); 
	gameplay(a);
	gameover();
	
	return 0;
}
void gotoxy(int x, int y)//λ�ú��� 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
} 

void gamestart(int (*a)[K]) //��ʼ����ʼ���� 
{
	int i, j, k;
	for(i=0; i<H-2; i++)
	{
		for(j=0; j<K; j++)
		{
			if(i==0 ||i==H-3 || j==0 || j==K-1 ||j==10)//���߿� 
				a[i][j]=-1;
			else
				a[i][j]=0;
		}
	}
	for(i=5; i>0; i--)//���� 
	a[15][25-i]=i;
	
	int fx, fy;    //��ʳ�� 
	srand(time(NULL));
	do{
		fx=rand()%25 + 2;
		fy=rand()%45 + 14;
	}while(a[fx][fy]!=0); 
	a[fx][fy]=-2;
	
	//����ʼ���ֺͷ���, -5�����ո� �� -6��1�ո� , 0��2�ո� 
	a[9][2]=-11;
	for(k=3; k<7; k++)
		a[9][k]=-5;
	a[9][7]=-6;
	
	a[11][2]=-9;
	a[12][2]=-8; 
	for(k=3; k<7; k++)
	{
		a[11][k]=-5;  a[12][k]=-5;
	}
	a[11][7]=-6; a[12][7]=-6;
	
	a[24][2]=-10; a[24][3]=-5; a[24][4]=-5; a[24][5]=-6;
	
	show(a);
}

void show(int (*a)[K])//��Ϸ��ʾ 
{
	gotoxy(0, 0);
	int i, j;
	system("color b0");
	for(i=0; i<H-1; i++)           
	{
		for(j=0; j<K; j++)
		{
			if(a[i][j]==0)
				printf("  ");
			if(a[i][j]==-6)
				printf(" ");
			if(a[i][j]==-1)
				printf("��");
			if(a[i][j]>1)
				printf("��");
			if(a[i][j]==1)
				printf("��");
			if(a[i][j]==-2)
				printf("��");
			if(a[i][j]==-20)
				printf("��");
			if(a[i][j]==-9)
				printf("[w]�� [s]��");
			if(a[i][j]==-8)
				printf("[a]�� [d]��"); 
			if(a[i][j]==-10)
				printf("�÷֣�%d", score);
			if(a[i][j]==-11)
				printf("[j]ѡ���ٶ�");
		}
		printf("\n");
	}
	//getchar();
}

void gameplay(int (*a)[K])        //��Ϸ�� 
{
	char move, move1;
	while(1)
	{
		move=getch();
		if(move=='d' || move=='w' || move=='s')
		break;
	}
	while(1)
	{
		if(a[0][0]==-3)
		break;
		if(kbhit())
		move=getch();
		if(move=='a'&&move1!='d'||move=='d'&&move1!='a'||
		move=='w'&&move1!='s'||move=='s'&&move1!='w')
		{
			move1=move;
			Smove(move1, a);
			show(a);
			Sleep(V);
		}
		if(move=='a'&&move1=='d'||move=='d'&&move1=='a'||
		move=='w'&&move1=='s'||move=='s'&&move1=='w')
		{
			Smove(move1, a);
			show(a);
			Sleep(V);
		}
	}
}

void Smove(char move, int (*a)[K])         //���������������ƶ� 
{
	int i, j, hx, hy, max=0, wx, wy;
	for(i=1; i<H-1; i++)
	{
		for(j=1; j<K-1; j++)
		{
			if(a[i][j]>0)
			{
				a[i][j]++;
				if(a[i][j]>max)
				{
					max=a[i][j];
					wx=i; wy=j;
				} 
				if(a[i][j]==2)
				{
					hx=i; hy=j;
				}
			}	
		}
	}
	int hx1, hy1;
	if(move=='d')//����
	{
		hx1=hx; hy1=hy+1;
	}
	if(move=='w')//�� 
	{
		hx1=hx-1; hy1=hy;
	}
	if(move=='s')//�� 
	{
		hx1=hx+1; hy1=hy;
	}
	if(move=='a')//�� 
	{
		hx1=hx; hy1=hy-1;
	}
	
	if(a[hx1][hy1]==-2 || a[hx1][hy1]==-20)  //�Ե�ʳ�� 
	{
		if(a[hx1][hy1]==-2)
		{
			foodsum++;
			score+=10;
		} 
		else
			score+=100;
			
		if(score>9 && score<100) a[24][5]=-5;
		if(score>99) a[24][6]=-6; 
		if(score>999) a[24][6]=-5;
		a[hx1][hy1]=0;
		food(a);
	}
	else{
		a[wx][wy]=0;
	}
	if(a[hx1][hy1]>1 || a[hx1][hy1]==-1) //���Լ���ײǽ 
	{
		a[0][0]=-3;
	}
	else
	{
		a[hx1][hy1]=1;
	}
}

void food(int (*a)[K])//�����µ�ʳ�� 
{
	int fx, fy;
	srand(time(NULL));
	do{
		fx=rand()%25 + 2;
		fy=rand()%45 + 14;
	}while(a[fx][fy]!=0);
	//printf("%d %d\n", fx, fy);
	if(foodsum==5)
	{
		foodsum=0;
		a[fx][fy]=-20;
	}
	else
		a[fx][fy]=-2;
} 

void changevelocity()
{
	int m=2;
	char ve, ch;
	ch=getch();
	show2(m);
	if(ch=='j')
	{
		while(1)
		{
			ve=getch();
			if(ve=='=')
			{
				V-=50;
				m++;
				if(V<=350 && V>=0)
				show2(m);
			}
			if(ve=='-')
			{
				V+=50;
				m--;
				if(V<=350 && V>=0)
				show2(m);
			}
			if(ve==13)
			{
				system("cls");
				show(a);
				break;
			}
		}
	}
}

void gameover()
{
	//system("cls");
	gotoxy(50, 12);
	printf("GAME OVER!");
	gotoxy(50, 13);
	printf("��ĵ÷֣�%d", score);
}

void show2(int m)
{
	int i;
	gotoxy(55, 7);
	printf("��"); 
	for(i=0; i<m; i++)
	{
		printf("��");
	}
	for(i=0; i<(8-m); i++)
		printf("  ");
	printf("��");
	gotoxy(58, 8);
	printf("-   �س�ȷ��  +");
	
}
 

