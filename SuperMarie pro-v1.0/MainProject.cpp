#include <stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>
#include "MarieDisplayFunction.h"
int main()
{ 
	IMAGE img;
	initgraph(1280,720);
	loadimage(&img, _T("test.jpg"));
	putimage(0, 0, &img);
	
	_getch();
	closegraph();
}