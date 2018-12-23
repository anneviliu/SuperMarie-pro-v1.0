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
extern double cur_positionX; //人物当前横坐标	
extern double cur_positionY; //人物当前纵坐标
extern double old_positionX; 
extern double old_positionY;
extern double real_positionX; //人物实际横坐标
extern double real_positionY; //人物实际纵坐标
extern double map_position; //地图位置
extern double hero_vx; //人物水平速度	
extern double hero_vy; //人物竖直速度
extern int num;
extern IMAGE img_hero_right[3],img_level1;
extern IMAGE img_hero_die[3];
extern IMAGE img_hero_left[3];
extern double cur_vx;
extern double cur_vy;
extern double h_now;
extern double acceleration_left;
extern double acceleration_right;
extern double friction; 
extern double friction_n;
extern int is_jump;
extern int is_die;
extern int is_replay;
extern int can_forward;
extern int temp;
extern int game_state;
extern int is_left;
extern int is_right;
extern int can_left;
extern int can_right;
extern struct Blank;
extern struct Block;
extern struct Gold;


#endif