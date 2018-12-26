#pragma once
#ifndef MARIEDISPLAYFUNCTION_H
#define MARIEDISPLAYFUNCTION_H
#include <stdio.h>

void game_start(); //游戏开始主界面
void show();
void game_show();
void help_page();  //游戏操作说明界面
void introduction_Page(); //游戏简介界面
//void Hero_TurnLeft(); //主角向左移动
//void Hero_TurnRight(); //主角向右移动
void gold_show();
void between_enemy_show(int i, double left, double right);
void enemy_show(int i, int direction);
void begin();
void preload();
void map_show();
void hero_die_show();
void hero_die_menu_show();
void brick_show();
void acmusic_control();
void flower_show();
void final_show();

void develop_mode(); //开发调试模式，看变量状态



#endif 