#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include <graphics.h>

int hero_move()
{
	char key = _getch();
	switch (key)
	{

	 case 'a':
	 case 'A':
		return CMD_LEFT;
		break;
		
	 case 'd':
	 case 'D':
		 return CMD_RIGHT;
		break;
	default:
		break;
	}
}