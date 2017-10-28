
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#pragma comment(lib,"Winmm.lib")
#define WIDTH 700
#define HEIGHT 900
int score,score_i;
//int map[4][4]={{1024,2,1024,4},{2,4,2,4},{4,2,4,16},{2,4,8,0}};
int map[4][4]={0};

void lent();
void lose();
void show1()
{
	cleardevice();//����

	setfont(70,0,"�����кڼ���");//��������
	RECT r1={0,0,WIDTH,HEIGHT/3};
	drawtext("��ӭ����2048������",&r1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	setfont(30,0,"΢���ź�");
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("��ʼ��Ϸ",&r2,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
	drawtext("��Ϸ����",&r3,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("����˵��",&r4,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("�˳���Ϸ",&r5,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	setfillcolor(RGB(244,186,1));//���õ�ǰ�������ɫ
	solidroundrect(216,478,484,746,50,50);
	setfont(145,0,"Microsoft Yahei UI Bold");//��������
	settextcolor(RGB(254,253,249));
	setbkcolor(RGB(244,186,1));//����ɫ
	outtextxy(216,535,"2048");//����ַ���2048

	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));//������ɫ
	setfont(30,0,"Microsoft Yahei Ul Boid");

}
void show2()
{
	cleardevice();//����
	RECT C2={60,60,640,790};
	drawtext("\n\n\n\n    ��Ϸ���ܣ�ÿ�ο���ѡ��������������һ������ȥ������ÿ����һ�Σ��������ַ��鶼������������£��ϵͳҲ���ڿհ׵ط��������һ�����ַ��飬��ͬ���ֻ��ڿ�£��ײʱ��ӡ����ϵĵ��ӣ�������ƴ�ճ�2048������־���ɹ�\n\n\n\n\n   �����ߣ���̿��Ͷday",&C2,DT_WORDBREAK);

	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("����",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				lent();
		}
	}
}

void show3()
{
	cleardevice();//����
	RECT C1={60,60,640,790};
	drawtext("\n\n\n����˵����\n\n���ƣ�A��/�������\n\n���ƣ�D��/�������\n\n���ƣ�W��/�������\n\n���ƣ�S��/�������\n\n(���أ�����OS:������� (��^��)�g)", &C1, DT_WORDBREAK);
	
	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("����",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				lent();
		}
	}
}

void show4()
{
	cleardevice();//����
	setfont(145,0,"Microsoft Yahei UI Bold");
	settextcolor(RGB(120,116,101));//��������
	outtextxy(15,0,"2048");

	setfillcolor(RGB(184,175,160));//���õ�ǰ�����ɫ
	solidroundrect(390,10,530,80,15,15);//Բ������
	setfont(28,0,"Microsoft Yahei UI Bold");//���õ�ǰ����
	setbkcolor(RGB(184,175,160));//������ɫ
	settextcolor(RGB(248,247,241));//������ɫ
	outtextxy(435,20,"�÷�");
	 
	char str[10],str_i[10];
	setbkcolor(RGB(184,175,160));
	itoa(score_i,str_i,10); 
	outtextxy(450,52,str_i);//����

	solidroundrect(550,10,690,80,15,15);//Բ������
	outtextxy(600,20,"�ܷ�");
	setbkcolor(RGB(184,175,160));
	itoa(score,str,10); 
	outtextxy(605,52,str);//����

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,95,690,137,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(498,100,"������ҳ��(esc)");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,152,690,195,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(520,160,"���¿�ʼ(t)");

	setfillcolor(RGB(187,173,160));
	solidroundrect(10,210,690,890,20,20);

	int i,j;
	for(i=0;i<4;i++)
	{
		setfillcolor(RGB(206,192,181));
		for(j=0;j<4;j++)
		{
			solidroundrect(30+165*i,230+165*j,175+165*i,375+165*j,5,5);
		}
	}
	IMAGE img0,img2,img4,img8,img16,img32,img64,img128,img256,img512,img1024,img2048;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			switch(map[j][i])
			{
				case 0:loadimage(&img0,"pic\\0.jpg");putimage(i*165+30,j*165+230,&img0);break;
				case 2:loadimage(&img2,"pic\\2.jpg");putimage(i*165+30,j*165+230,&img2);break;
				case 4:loadimage(&img4,"pic\\4.jpg");putimage(i*165+30,j*165+230,&img4);break;
				case 8:loadimage(&img8,"pic\\8.jpg");putimage(i*165+30,j*165+230,&img8);break;
				case 16:loadimage(&img16,"pic\\16.jpg");putimage(i*165+30,j*165+230,&img16);break;
				case 32:loadimage(&img32,"pic\\32.jpg");putimage(i*165+30,j*165+230,&img32);break;
				case 64:loadimage(&img64,"pic\\64.jpg");putimage(i*165+30,j*165+230,&img64);break;
				case 128:loadimage(&img128,"pic\\128.jpg");putimage(i*165+30,j*165+230,&img128);break;
				case 256:loadimage(&img256,"pic\\256.jpg");putimage(i*165+30,j*165+230,&img256);break;
				case 512:loadimage(&img512,"pic\\512.jpg");putimage(i*165+30,j*165+230,&img512);break;
				case 1024:loadimage(&img1024,"pic\\1024.jpg");putimage(i*165+30,j*165+230,&img1024);break;
				case 2048:loadimage(&img2048,"pic\\2048.jpg");putimage(i*165+30,j*165+230,&img2048);break;
			}
		}
	}

}
int judge()
{
	int i,j;
	//����Ƿ���0ֵ
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(map[i][j]==0)
				return 0;
	//�鿴�߽��Ƿ�����ͬ��
	for(i=0;i<4;i+=3)
		for(j=1;j<3;j++)
			if(map[i][j-1]==map[i][j]||map[i][j+1]==map[i][j])
				return 1;
	for(i=1;i<3;i++)
		for(j=0;j<4;j+=3)
			if(map[i-1][j]==map[i][j]||map[i+1][j]==map[i][j])
				return 1;
	//�鿴�����Ƿ�����ͬ
	for(i=1;i<3;i++)
		for(j=1;j<3;j++)
			if(map[i-1][j]==map[i][j]||map[i+1][j]==map[i][j]||map[i][j-1]==map[i][j]||map[i][j+1]==map[i][j])
				return 1;
	lose();
}
void rands()
{
	int x,y,temp,num;
	srand((int)time(0));
	while(1)
	{
		x=rand()%4;
		y=rand()%4;
		temp=rand()%5;
		if(temp==1)
			num=4;
		else 
			num=2;
		if(map[y][x]==0)
		{
			map[y][x]=num;
			break;
		}
		if(judge())
			break;
	}
}
void updateWithInput()//�������йصĸ���
{
	char keyboard;
	if(kbhit())
	{	keyboard=getch(); 
		EndBatchDraw();//����������ͼ
		score_i=0;
	}
	int i,j,n,num=0;
	if(keyboard=='w'||keyboard=='W'||keyboard==72)//��
	{
		for(n=0;n<4;n++)//����
		for(i=1;i<4;i++)//��
		for(j=0;j<4;j++)//��
			if(map[i][j]!=0)
			{
				if(map[i-1][j]==0)
				{
					map[i-1][j]=map[i][j];
					map[i][j]=0;
				}
				if(map[i-1][j]==map[i][j])
				{
					num=map[i][j]*2;//�÷�
					score_i=score_i+num;
					map[i-1][j]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			score=score+score_i;
			rands();
	}
	else if(keyboard=='s'||keyboard=='S'||keyboard==80)//��
	{
		for(n=0;n<4;n++)//����
		for(i=2;i>=0;i--)//��
		for(j=0;j<4;j++)//��
			if(map[i][j]!=0)
			{
				if(map[i+1][j]==0)
				{
					map[i+1][j]=map[i][j];
					map[i][j]=0;
				}
				if(map[i+1][j]==map[i][j])
				{
					num=map[i][j]*2;//�÷�
					score_i=score_i+num;
					map[i+1][j]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			score=score+score_i;
			rands();
	}
	else if(keyboard=='a'||keyboard=='A'||keyboard==75)//��
	{
		for(n=0;n<4;n++)//����
		for(i=0;i<4;i++)//��
		for(j=1;j<4;j++)//��
			if(map[i][j]!=0)
			{
				if(map[i][j-1]==0)
				{
					map[i][j-1]=map[i][j];
					map[i][j]=0;
				}
				if(map[i][j-1]==map[i][j])
				{
					num=map[i][j]*2;//�÷�
					score_i=score_i+num;
					map[i][j-1]=map[i][j]*2;
					map[i][j]=0;
				}
			}
			score=score+score_i;
			rands();
	}
	else if(keyboard=='d'||keyboard=='D'||keyboard==77)//��
	{
		for(n=0;n<4;n++)//����
		for(i=0;i<4;i++)//��
		for(j=2;j>=0;j--)//��
			if(map[i][j]!=0)
			{
				if(map[i][j+1]==0)
				{
					map[i][j+1]=map[i][j];
					map[i][j]=0;
				}
				if(map[i][j+1]==map[i][j])
				{
					num=map[i][j]*2;//�÷�
					score_i=score_i+num;
					map[i][j+1]=map[i][j]*2;
					map[i][j]=0;
				}
			}
		score=score+score_i;
		rands();	
	}
	else if(keyboard==27)
		lent();
	else if(keyboard=='t')
	{
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				map[i][j]=0;
			score=0;
			rands();
			rands();
	}
}
void win()
{
	mciSendString("close music", NULL, 0, NULL);
	mciSendString("open \"pic\\win.mp3\" alias music ", NULL, 0, NULL);//��������
	mciSendString("play music", NULL, 0, NULL);
	cleardevice();//����
	settextcolor(RGB(249,6,43));
	setfont(40,0,"Microsoft Yahei UI Bold");
	RECT C2={100,400,640,790};
	drawtext("��ϲ�������2048��С�ϳϾ�������һ����������Ϊ����Ľ���_(:�١���)_",&C2,DT_WORDBREAK);
	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("�ص���ҳ��",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				lent();
		}
	}

}
void lose()
{
	mciSendString("close music", NULL, 0, NULL);
	mciSendString("open \"pic\\ʧ��.mp3\" alias music ", NULL, 0, NULL);//��������
	mciSendString("play music", NULL, 0, NULL);

	cleardevice();//����
	settextcolor(RGB(0,0,0));
	setfont(40,0,"Microsoft Yahei UI Bold");
	RECT C2={100,400,640,790};
	drawtext("2048����ɲ��ˣ����� ���أ������棡����",&C2,DT_WORDBREAK);
	RECT R1={2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("�ص���ҳ��",&R1,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if(m.x>2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				lent();
		}
	}

}
void start()
{
	
	MOUSEMSG m;
	int i,j;
	for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				map[i][j]=0;
	rands();
	rands();
	while(1)
	{
		show4();
		BeginBatchDraw();//������ͼ������˸
		setbkcolor(RGB(251,248,241));
		updateWithInput();//�������йصĸ���
		if(score_i>=2048)
			win();	
	}

}
void lent()
{
	mciSendString("open \"pic\\��������.mp3\" alias music ", NULL, 0, NULL);//��������
	mciSendString("play music", NULL, 0, NULL);
	initgraph(WIDTH,HEIGHT);//����
	setbkcolor(RGB(251,248,241));//����
	settextcolor(RGB(150,126,104));

	
	MOUSEMSG m;
	while(1)
	{
		show1();
		BeginBatchDraw();//������ͼ
		m=GetMouseMsg();//��ȡ�����Ϣ
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			EndBatchDraw();//����������ͼ
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)
				start();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)
				show2();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+60&&m.y<HEIGHT/3+90)
				show3();
			
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+90&&m.y<HEIGHT/3+120)
				exit(0);
		}
	}
	getch();

}
int main (void)
{
	
	lent();
}

