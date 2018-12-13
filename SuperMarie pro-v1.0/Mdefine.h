#pragma once
#ifndef MDEFINE_H
#define MDEFINE_H


#define HIGH 720 //屏幕高
#define WIDTH 1280 //屏幕宽
#define LIFE 4 //主角暂且有4条生命
#define STEP 10 //主角每走一步相距的像素个数
#define ENEMY_STEP 1 //敌人每走一步相距的像素个数
#define HERO_INIT_Y HIGH-120

#define GRAVITY 10 .0
#define ACCELERATION 3.0
#define FRICTION 2.0
#define TIME 3.0
#define H_MAX 400


#define ESC 27 //ESC键对应的键码
#define CMD_LEFT 4 //主角左移
#define CMD_RIGHT 6 //主角右移
#define CMD_JUMP 8 //主角跳跃
#define CMD_RELEASE 0 //按键处在放开状态
#endif //MDEFINE_H