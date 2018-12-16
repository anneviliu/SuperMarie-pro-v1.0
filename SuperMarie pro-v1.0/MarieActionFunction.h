#ifndef MARIEACITONFUNCTION_H
#define MARIEACITONFUNCTION_H
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "Mdefine.h"
#include "main.h"
#include "MarieDisplayFunction.h"
#include <time.h>

void hero_move(); //控制左右移动
void HpSleep(int ms);  
double shift_x(double *v,double t,double a);//计算人物位移，加速度实现
double shift_y(double *v,double t,double a);//计算人物位移，加速度实现

void bkg_move(); //控制背景的移动

#endif 