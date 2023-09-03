#pragma once
#include"level0.h"
#include"functions.h"

//所有的全局变量的声明

extern int players;
extern int boss0_exist;
extern int bullet;
extern char boss0_move;
extern int x_boss0;
extern int y_boss0;
extern int hp_boss0;
extern int maxj, maxd;
extern int map[screen_height][map_length];
extern char prev_direction;						//-------------新:新增全局变量pre_direction,即前一个操作的方向
extern char direction;
extern char ch1;
extern char ch2;
extern int x, y;								//玩家头的坐标
extern int dist_jump;
extern int mark_jump;
extern int dist_down;
extern int mark_down;
extern int timenow;
extern int timenow1;
extern boss a;
extern int temp1;
extern char menu_view[screen_height][screen_length];
extern char help_view[screen_height][screen_length];
extern char mapchoose_view[screen_height][screen_length];
extern int aa;
extern int eflag;
extern int eflag1;
extern int flag3;								//退出标志
extern int bullet_exist;
extern int bullet;
extern char boss0_move;

void clean_screen();
