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
void enemy_show(int i);
void begin();
void preload();
void map_show();
void hero_die_show();
void hero_die_menu_show();
void mic_control();
void develop_mode(); //开发调试模式，看变量状态

#endif