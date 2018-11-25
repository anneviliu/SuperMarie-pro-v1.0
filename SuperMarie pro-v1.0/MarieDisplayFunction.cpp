#include "MarieDisplayFunction.h"
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void start_show()
{
	IMAGE img;
	initgraph(1280, 720);
	loadimage(&img,_T("test.jpg"));
	putimage(0, 0, &img);

	_getch();
	closegraph();

}