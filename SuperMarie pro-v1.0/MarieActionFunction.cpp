#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>




int move()
{
	if (_kbhit())
	{
		char actionType = _getch();
		if (actionType == 'a' && x > 0)
		{ 
			return CMD_LEFT;              // 左移
		}
		if (actionType == 'd' && x < WIDTH)
		{
			return CMD_RIGHT;               //右移
		}
		if (actionType == 'w'&&y > 0)
		{
			return CMD_JUMP;         //跳跃
		}
	}
}