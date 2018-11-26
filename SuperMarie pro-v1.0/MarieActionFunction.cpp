#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>
void move(IMAGE img)
{
	int x = WIDTH, y = HIGH;
	
	char ch = _getch();
	if (ch == 'a' && x > 0)
	{
		moverel(-1, 0);              // 左移
	}                         
	if (ch == 'd' && x < WIDTH)
	{
		moverel(1, 0);               //右移
	}
}