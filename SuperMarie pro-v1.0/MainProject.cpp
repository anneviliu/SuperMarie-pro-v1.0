#include <stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include "Marie.h"
int main()
{ 
	printf("%d\n", add(1, 2));
	IMAGE img(640, 480);
	SetWorkingImage(&img);

	initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
	loadimage(NULL, _T("C:\\Ccccc\\超级玛丽\\素材库\\test.jpg"));

	setlinecolor(RED);
	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	SetWorkingImage();

	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}