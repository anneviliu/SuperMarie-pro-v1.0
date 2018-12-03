#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>

#define ACTION_XX 'a'


void move(IMAGE img)
{
	int x = 0, y = 0;
	
	char actionType = _getch();
	if (actionType == 'a' && x > 0)
	{
		x-=1;              // 左移
	}                         
	if (actionType == 'd' && x < WIDTH)
	{
		x+=1;               //右移
	}
}