#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#pragma comment(lib,"Winmm.lib")

void start_show()
{
	int i=0;
	IMAGE img_preplay;
	initgraph(1280, 720);
	loadimage(&img_preplay, _T("res\\level_1.png"));
	mciSendString("open res\\±≥æ∞“Ù¿÷.mp3 alias music_back", NULL, 0, NULL);
	mciSendString("play music_back", NULL, 0, NULL);
	while (1)
	{
		i=i+10;
		putimage(0, 0, 1280, 730, &img_preplay, i, 0);
		if (i == 6126)	//øÿ÷∆”Œœ∑≤Àµ•ΩÁ√Ê±≥æ∞¬÷πˆ
			i = 0;
		Sleep(100);
	}
	_getch();
	closegraph();
}