#include"MarieActionfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	 case 'w':
	 case'W':
		 return CMD_JUMP;
	default:
		break;
	}
}


double shift(double *v,double t,double a){
	double h = *v * t + 1 / 2.0*a*t*t;
	if (fabs(*v) >= 10&&a*(*v)>0)
		return h;
	*v = *v + a * t;
	return h;
}