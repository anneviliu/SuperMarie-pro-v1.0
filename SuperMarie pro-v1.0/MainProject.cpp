#include <stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>
#include "MarieDisplayFunction.h"
#include <stdbool.h>
#include "MarieActionFunction.h"
#pragma comment(lib,"Winmm.lib")

int main()
{
	IMAGE img1;
	menu_show();
	loadimage(&img1, _T("res\\test.jpg"));
	move(img1);

	return 0;
}