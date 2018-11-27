/******************************************************************
 *				       SuperMarie Pro V1.0	     	               *
  *			     By HDU_CBS Annevi ADobie Yuahwg 			   	    *
 *					 	  2018-11-26---						       *
******************************************************************/
//				//									\\
               //									 \\
			  //									  \\

#include "MarieDisplayFunction.h"
#include "MarieActionFunction.h"
#include "control.h"
#include "Mdefine.h"
#include <stdbool.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib,"Winmm.lib")

//全局变量
int life = LIFE;
int world = 1;

int main()
{
	initgraph(WIDTH, HIGH);
	GameStart();
	

	return 0;
}