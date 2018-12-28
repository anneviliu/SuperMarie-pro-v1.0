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
int is_success = 0;
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
IMAGE img_play_again[3];
IMAGE img_quit_game[3];
IMAGE img_hero[3], img_level1;
IMAGE img_hero_die[3],img_gold[3],img_enemies[3], img_brick[3],img_wh_brick[3], img_qm_brick[3];
IMAGE img_hero_left[3], img_hero_right[3];
IMAGE img_score[3];
IMAGE img_success[3];
IMAGE img_flower[3], img_enemy_die[3];
IMAGE img_final_step[3], img_final_flag[3];
IMAGE img_final_home[3];

/*游戏状态标识
 =============================================
 *	game_state	|	1	  |		2	 |   3    *
 *______________|_________|__________|______ _*
 *	   意义	    |游戏主菜单|游戏主界面 |通关成功 *
 =====================================
*/

int main()
{

	while (true)
	{
		if (game_state == 1) //菜单界面
		{
			preload(); //预加载 初始化数据
			begin(); //开始前
			//game_start();
			game_show(); //游戏初始界面
		}
		else if (game_state == 2) //游戏中
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
			
			else if (game_state ==3)  //通关
			{
				can_left = 0;
				can_right = 0;
				//can_forward = 0;
				
				putimage(220, 60, 800, 500, &img_success[1], 0, 0);
				success_button();
				mciSendString("clase all", NULL, 0, NULL); //关闭所有多媒体音乐文件
				mciSendString("open res\\通关.mp3 alias music_success", NULL, 0, NULL); //加载通关音效
				mciSendString("play music_success", NULL, 0, NULL); //背景音乐

			}
			
			EndBatchDraw();
		}
	}
	closegraph();
	system("pause");
	return 0;
}