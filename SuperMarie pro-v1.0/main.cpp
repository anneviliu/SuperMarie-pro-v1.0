/******************************************************************
 *				       SuperMarie Pro V1.0	     	               *
  *			     By HDU_CBS Annevi ADobie Yuahwg 			   	    *
 *					 	  2018-11-26---						       *
******************************************************************/
//									\\
               //									 \\
			  //									  \\



#include "main.h"
#pragma comment(lib,"Winmm.lib")

//全局变量
//============================================//
int life = LIFE;
int world = 1;

double cur_positionX = 0;
double cur_positionY = HIGH - 120;
double old_positionX = 0;
double old_positionY = HIGH - 120;
double real_positionX = 0;
double real_positionY = HIGH - 120;
double map_position = 0;
double hero_vx = 0;
double hero_vy = 0; //
double cur_vx = 0; //当前水平速度记录 录
double cur_vy = 0; //当前竖直方向速度记
double h_now = 0; //目前高度
int develop_flag = 0;
int is_left = 0;
int is_right = 0;
int can_left= 1;
int can_right= 1;
int is_jump = 0; //是否跳跃
int is_die = 0;
int is_replay = 0;
int is_get_score = 0;
int is_touch_gold = 0;
int is_touch_brick = 0;
int can_forward = 1;
int game_state = 1;
int touch_count[11] = {0};
int temp = 0;
int num_hero = 0,num_gold = 0, num_brick=1 ,num_fw=0; //实现人物的步伐动作
int wh_brick_count = 0;
int cur_direction[7] = { 0 };
int score = 0;
int enemy_can_move = 1;
Gold gold[11];
Enemy enemy[6];

IMAGE img_hero[3], img_level1;
IMAGE img_hero_die[3],img_gold[3],img_enemies[3], img_brick[3],img_wh_brick[3], img_qm_brick[3];
IMAGE img_hero_left[3], img_hero_right[3];
IMAGE img_score[3];
IMAGE img_flower[3], img_enemy_die[3];
IMAGE img_final_step[3], img_final_flag[3];
IMAGE img_final_home[3];
/*游戏状态标识
 =====================================
 *	game_state	|	1	  |		2	 *
 *______________|_________|__________*
 *	   意义	    |游戏主菜单|游戏主界面 *
 =====================================
*/

int main()
{

	while (true)
	{
		if (game_state == 1)
		{
			preload(); //预加载 初始化数据
			begin(); //开始前
			//game_start();
			game_show(); //游戏初始界面
		}
		else if (game_state == 2)
		{ 
			BeginBatchDraw();
			hero_move(); //人物移动
			judge(); // 障碍判定等
			show(); //显示画面
			if (is_die == 1) //如果人物死亡
			{
				hero_die_show(); //人物死亡形象
				HpSleep(1000 * 3); //等待死亡音乐播放完毕3.0s
				hero_die_menu_show(); //人物死亡效果显示
				preload(); //初始化数据
			}
			
			EndBatchDraw();
		}
	}
	//背景移动
	//人物射击（子弹发射，子弹飞行，子弹击中判定）
	//人物射击动画与音效
	//敌人显示，移动
	//人物与敌人碰撞判定（人物矩形左部或右部与敌人矩形左部或右部，人物矩形下部与敌人上部）
	//人物死亡判定
	//人物死亡动画与音效载入
	//如果死亡，弹出界面（重新开始或返回菜单）
	//敌人死亡判定
	//敌人死亡动画音效载入
	//硬币与人物矩形接触判定
	//吃到硬币动画与音效
	//计分板变化
	//人物与蘑菇接触判定
	//吃到蘑菇动画与音效
	//人物与终点接触判定
	//抵达终点后动画与音效
	//通关动画与音效
	//返回菜单或进入下一关
	mciSendString("clase all", NULL, 0, NULL);//关闭所有多媒体音乐文件
	closegraph();
	system("pause");
	return 0;
}