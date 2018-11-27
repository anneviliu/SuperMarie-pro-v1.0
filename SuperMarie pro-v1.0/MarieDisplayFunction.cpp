#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include "Mdefine.h"
#include "MarieActionFunction.h"	
#pragma comment(lib,"Winmm.lib")
 
void GameStart()
{
	cleardevice();
	settextstyle(40, 0, "微软雅黑");

	int i = 0;
	IMAGE img_preplay;
	IMAGE img_test;
	initgraph(WIDTH, HIGH);
	loadimage(&img_preplay, _T("res\\level_1.png"));
	loadimage(&img_test, _T("res\\test.jpg"));

	mciSendString("open res\\背景音乐.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL);
	putimage(0, 0, WIDTH, HIGH, &img_preplay, i, 0);
		putimage(0,y, &img_test);
		move(img_test);

	RECT r1 = { 0, 0, WIDTH, HIGH / 3 };
	drawtext("超级玛丽魔改版", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(50, 0, "微软雅黑");

	RECT r2 = { WIDTH / 2 - 125,HIGH / 3-40,WIDTH / 2 + 45,HIGH / 3 + 40 }; 
	rectangle(WIDTH / 2 - 125, HIGH / 3, WIDTH / 2 + 55, HIGH / 3 + 30);
	drawtext("开 始 游 戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	RECT r3 = { WIDTH / 2 - 85,HIGH / 3 + 30,WIDTH / 2 + 45,HIGH / 3 + 60 }; 
	rectangle(WIDTH / 2 - 85, HIGH /  3 + 30, WIDTH / 2 + 45, HIGH / 3 + 60);
	drawtext("游 戏 介 绍", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	 
	RECT r4 = { WIDTH / 2 - 85,HIGH / 3 + 60,WIDTH / 2 + 45,HIGH / 3 + 90 }; 
	rectangle(WIDTH / 2 - 85, HIGH / 3 + 60, WIDTH / 2 + 45, HIGH / 3 + 90);
	drawtext("操 作 说 明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	RECT r5 = { WIDTH / 2 - 85,HIGH / 3 + 90,WIDTH / 2 + 45,HIGH / 3 + 120 }; 
	rectangle(WIDTH / 2 - 85, HIGH / 3 + 90, WIDTH / 2 + 45, HIGH / 3 + 120);
	drawtext("退 出 游 戏", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	/*setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(50, 0, _T("黑体"));
	outtextxy(WIDTH*0.4, HIGH*0.4, "进入游戏");
	outtextxy(WIDTH*0.425, HIGH*0.5, "设置");*/
	
	FlushBatchDraw();
	Sleep(2);

	_getch();
	closegraph();
}
