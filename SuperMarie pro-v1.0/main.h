#pragma once
#ifndef MAIN_H
#define MAIN_H
#include "MarieDisplayFunction.h"
#include "MarieActionFunction.h"
#include "control.h"
#include "Mdefine.h"
#include <stdbool.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//全局变量
extern double cur_positionX;
extern double cur_positionY;
extern double old_positionX;
extern 	double old_positionY;
extern 	double hero_vx;
extern 	double here_vy;
extern 	int num;
extern 	IMAGE img_hero[3],  img_level1;
	


#endif