#include"level0.h"
#include"functions.h"

//所有的全局变量的定义

int boss0_exist;
int x_boss0 = 0;
int y_boss0 = 0;
int hp_boss0 = boss0_hp;
int maxj = 0, maxd = 0;
int map[screen_height][map_length];
char prev_direction = 'i';						//-------------新:新增全局变量pre_direction,即前一个操作的方向
char direction = 'i';
char ch1 = '0';
char ch2 = '0';
int x = 0, y = 0;								//玩家头的坐标
int dist_jump = 0;
int mark_jump = 0;
int dist_down = 0;
int mark_down = 0;
int timenow = 0;
int timenow1 = 0;
boss a;
int temp1 = 0;
char menu_view[screen_height][screen_length] = { 0 };
char help_view[screen_height][screen_length] = { 0 };
char mapchoose_view[screen_height][screen_length] = { 0 };
int aa = 0;
int eflag = 1;
int players = start_players;					//人物当前生命值
int eflag1 = 0;
int flag3 = 0;									//退出标志
int bullet_exist = 0;
int bullet = 0;
char boss0_move = '1';
