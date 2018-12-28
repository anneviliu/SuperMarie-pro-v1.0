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
#include <process.h>  
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
extern int num_hero,num_gold,num_brick,num_fw;
extern int wh_brick_count;
extern IMAGE img_hero[3],img_level1;
extern IMAGE img_hero_die[3],img_gold[3],img_enemies[3];
extern IMAGE img_hero_left[3],img_hero_right[3];
extern IMAGE img_brick[3], img_wh_brick[3],img_qm_brick[3];
extern IMAGE img_score[3];
extern IMAGE img_flower[3], img_enemy_die[3];
extern IMAGE img_final_step[3];
extern IMAGE img_final_flag[3];
extern IMAGE img_final_home[3];
extern IMAGE img_success[3];
extern IMAGE img_play_again[3];
extern IMAGE img_quit_game[3];
extern double cur_vx;
extern double cur_vy;
extern double h_now;
extern int touch_count[11];


extern int is_success;
extern int is_jump;
extern int is_die;
extern int is_replay;
extern int can_forward;
extern int temp;
extern int game_state;
extern int is_left;
extern int is_right;
extern int is_get_score;
extern int is_touch_gold;
extern int is_touch_brick;
extern int can_left;
extern int can_right;
extern int develop_flag;
extern int cur_direction[7];
extern int score;
extern int enemy_can_move;
extern struct Blank;
extern struct Block;

typedef struct Gold {
	double begin_x, begin_y;
	double final_x, final_y;
	int is_touch;
	int is_first_touch;
}Gold;
extern Gold gold[11];//金币数组

typedef struct Enemy {
	double cur_begin_x, cur_begin_y;
	double cur_final_x, cur_final_y;
	int is_touch;
	int first_die_put;
	int is_exist;
	int is_die;
	int rec_x;
	int rec_y;
	int is_first_touch;
	int enemy_can_move;
}Enemy;
extern Enemy enemy[6];


typedef struct Brick {
	double brick_positionX, brick_positionY;
}Brick;
extern Brick brick[5];


#endif 