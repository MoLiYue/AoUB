#include "functions.h"
#include<time.h>
#include<stdlib.h>
#include"level0.h"
#include"all.h"


void main_process()
{
	timenow = clock();

	timenow = clock();

    gameStage gg(aa);

	getMoving GM(1);

	GM.getch_part();			//将按键输入部分分离至入口外

	if (timenow % speed == 0 && timenow1 == timenow)
	{
		timenow1 += speed;
		a.boss_asset();
		GM.moving_part(map);
	    gg.Trigger();
		viewmove();
	}
}

void player_creator(int map[screen_height][map_length])
{

	map[head_x][head_y] = head_value;
	map[head_x + 1][head_y] = body_value;
	map[head_x + 1][head_y - 1] = body_value;
	map[head_x + 1][head_y + 1] = body_value;
	map[head_x + 2][head_y] = body_value;
	map[head_x + 3][head_y - 1] = body_value;
	map[head_x + 3][head_y + 1] = body_value;

	for (int j = 0; j < map_length; j++)
	{
		map[0][j] = EDGE;
	}


	for (int j = 0; j < map_length; j++)
	{
		map[screen_height - 1][j] = EDGE;
	}

}

