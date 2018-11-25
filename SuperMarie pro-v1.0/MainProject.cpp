#include <stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>

int main()
{ 
	IMAGE img(1280, 720);
	SetWorkingImage(&img);

	initgraph(1280,720);   // 创建绘图窗口，大小为 640x480 像素
	loadimage(&img, _T("test.jpg"));
	putimage(0, 0, &img);
	setlinecolor(RED);

	circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	SetWorkingImage();

	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}