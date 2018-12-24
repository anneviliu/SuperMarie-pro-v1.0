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
extern double real_positionX;
extern double real_positionY;
extern double map_position;
extern double hero_vx;
extern double hero_vy;
extern int num_hero,num_gold;
extern IMAGE img_hero[3],img_level1;
extern IMAGE img_hero_die[3],img_gold[3],img_enemies;
extern IMAGE img_hero_left[3],img_hero_right[3];

extern double cur_vx;
extern double cur_vy;
extern double h_now;
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
extern int develop_flag;
extern struct Blank;
extern struct Block;
typedef struct Gold {
	double begin_x, begin_y;
	double final_x, final_y;
	int is_touch;
}Gold;
extern Gold gold[10];//金币数组

typedef struct Enemy {
	double cur_positionX, cur_positionY;
}Enemy;
extern Enemy enemy[5];




#endif