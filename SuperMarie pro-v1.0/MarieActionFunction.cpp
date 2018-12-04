#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>




int move()
{	
	char ActionType = _getch();
	if (ActionType == 'a')
	{
		return CMD_LEFT;              // 左移
	}                         
	if (ActionType == 'd')
	{
		return CMD_RIGHT;              //右移
	}
}