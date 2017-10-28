#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

#define WIDTH 700
#define HEIGHT 900

int score;
void o1();
void o2();
void o3();
void start();

void lead()
{
	initgraph(WIDTH,HEIGHT);//����
	setbkcolor(RGB(251,248,241));//����
	settextcolor(RGB(150,126,104));
	o1();
}
void o1()
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

	MOUSEMSG m;
	while(1)
	{
		BeginBatchDraw();//������ͼ
		m=GetMouseMsg();//��ȡ�����Ϣ
		if(m.uMsg==WM_LBUTTONDOWN)
		{

				EndBatchDraw();//����������ͼ
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)
				start();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)
				o2();
		
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+60&&m.y<HEIGHT/3+90)
				o3();
			
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+90&&m.y<HEIGHT/3+120)
				exit(0);
		}
	}
	getch();

}
void o2()
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
				o1();
		}
	}
}
void o3()
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
				o1();
		}
	}

}
void start()
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
	outtextxy(435,20,"����");
	 
	solidroundrect(550,10,690,80,15,15);//Բ������
	outtextxy(590,20,"��߷�");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,95,690,137.5,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(525,100,"������ҳ��");

	setfillcolor(RGB(141,122,105));
	solidroundrect(480,152.5,690,195,15,15);
	setbkcolor(RGB(141,122,105));//������ɫ
	setfont(33,0,"Microsoft Yahei UI Bold");
	outtextxy(540,160,"���¿�ʼ");

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

	MOUSEMSG m;
	while(1)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			initgraph(WIDTH,HEIGHT);//����
			setbkcolor(RGB(251,248,241));//����
			settextcolor(RGB(150,126,104));
			if(m.x>480&&m.x<690&&m.y>95&&m.y<137.5)
				o1();

			if(m.x>480&&m.x<690&&m.y>152.5&&m.y<195)
				start();
		}
	}

}
int main(void)
{
	
	lead();
}
