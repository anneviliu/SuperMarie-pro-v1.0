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
extern double old_positionY;
extern double real_positionX;
extern double real_positionY;
extern double map_position;
extern double hero_vx;
extern double hero_vy;
extern int num;
extern IMAGE img_hero[3],img_level1;
extern double cur_vx;
extern double cur_vy;
extern double h_now;
extern double acceleration_left;
extern double acceleration_right;
extern double friction; 
extern double friction_n;
extern int is_jump;
extern int temp;
extern struct Blank;
extern struct Block;
extern struct Gold;


#endif