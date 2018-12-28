#pragma once
#ifndef MARIEDISPLAYFUNCTION_H
#define MARIEDISPLAYFUNCTION_H
#include <stdio.h>

void game_start(); //游戏开始主界面
void show(); //主显示函数
void game_show(); //游戏开始后显示的初始界面
void help_page();  //游戏操作说明界面
void introduction_Page(); //游戏简介界面
void gold_show(); //金币显示
void between_enemy_show(int i, double left, double right); //在两个水柱之间的敌人运动显示
void enemy_show(int i, int direction); //在正常情况下的敌人显示
void begin(); //载入图片、音乐等素材
void preload(); //预载入：变量初始化
void map_show(); //地图显示控制
void hero_die_show(); //人物死亡时的样子
void hero_die_menu_show(); //人物死亡之后的菜单
void brick_show(); //砖块显示
void flower_show(); //花的显示
void final_show(); //到达终点区域的相关物件显示
void score_show(); //分数显示
void develop_mode(); //开发调试模式，看变量状态
void success_button(); 



#endif 