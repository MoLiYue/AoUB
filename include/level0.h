#pragma once
#ifndef LEVEL0
#define LEVEL0

#include "functions.h"
#include<iostream>
#include <stdlib.h>
#include <math.h>
//#include<windows.h>
//#include<conio.h>
#include<time.h>

using namespace std;
//#include<Windows.h>
//#include<mmsystem.h>
//#pragma comment(lib,"WINMM.LIB")

#define start_players 3//人物初始生命值



class gameStage
{
private:
	//static int eflag;
	int index;
protected:
	void restart_boss0noExist(int i);
	void Level_0_game_finished();
	void Level_1_game_finished();
	void restart_boss0exist();
	void player_died(int n);
public:
	gameStage() {};
	gameStage(int i);
	void stageSet();
	void Level_0_asset();
	void Level_1_asset();
	void Level_2_asset();
	void Trigger();
};

class getMoving
{
public:
	getMoving(int i);
	~getMoving() = default;

	void getch_part();
	void moving_part(int map[screen_height][map_length]);
	void check_height_up(void);
	void check_height_down();
	void attack_l();
	void attack_r();
private:
	int start;
};



#endif // !LEVEL0
