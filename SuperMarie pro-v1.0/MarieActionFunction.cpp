#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>

void move()
{
	IMAGE Hero, Hero_mask, img_level1;
	static int position_back = 0;
	static int position_forward = 0;
	loadimage(&Hero, _T("res\\主角.png"));
	loadimage(&Hero_mask, _T("res\\主角（遮罩）"));
	loadimage(&img_level1, _T("res\\level1.png"));

	char key = _getch();
	switch (key)
	{

	 case 'a':
	 case 'A':
		
		putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
		putimage(-1*position_back * 10, HIGH - 120, 35, 50, &Hero, 210, 80);
		position_back++;
		
	 case 'd':
	 case 'D':

		putimage(0, 0, WIDTH, HIGH, &img_level1, 0, 0);
		putimage(1 * position_forward * 10, HIGH - 120, 35, 50, &Hero, 210, 80);
		position_forward++;

	default:
		break;
	}
}