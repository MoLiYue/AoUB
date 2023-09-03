// #include "stdafx.h"
#include "functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN64)
#include <conio.h>
#include <windows.h>
#else
#include <curses.h>
#endif
#include <time.h>
// #include<Windows.h>
// #include<mmsystem.h>
// #pragma comment(lib,"WINMM.LIB")

#define start_players 3 // 人物初始生命值

extern int hp_boss0;
extern int players = start_players; // 人物当前生命值
extern int boss0_exist;
extern int bullet;
extern int eflag;
extern int eflag1 = 0;
extern int map[screen_height][map_length];

// 地图中无boss存在，死亡后复活在死亡坐标前最近的安全地点
void restart_boss0noExist(int i) {
  while (map[head_x][i] != 0 || map[head_x + 1][i] != 0 ||
         map[head_x + 1][i - 1] != 0 || map[head_x + 1][i + 1] != 0 ||
         map[head_x + 2][i] != 0 || map[head_x + 3][i - 1] != 0 ||
         map[head_x + 3][i + 1] != 0) {
    i -= 3;
  }

  map[head_x][i] = head_value;
  map[head_x + 1][i] = body_value;
  map[head_x + 1][i - 1] = body_value;
  map[head_x + 1][i + 1] = body_value;
  map[head_x + 2][i] = body_value;
  map[head_x + 3][i - 1] = body_value;
  map[head_x + 3][i + 1] = body_value;
}

// 地图中生成了boss，死亡后复活在游戏初始位置
void restart_boss0exist() {
  map[head_x][head_y] = head_value;
  map[head_x + 1][head_y] = body_value;
  map[head_x + 1][head_y - 1] = body_value;
  map[head_x + 1][head_y + 1] = body_value;
  map[head_x + 2][head_y] = body_value;
  map[head_x + 3][head_y - 1] = body_value;
  map[head_x + 3][head_y + 1] = body_value; // 初始化小人位置
}

// 死亡判定函数
void player_died(int n) {
  int i, Trigger_time = clock(); // 触碰陷阱（cone）的时间
  int Present_time = 0;          // 定义变量“当前时间”

  players--;     // 生命值-1s
  system("cls"); // 清屏，切换到死亡界面
  bullet = 0;

  for (i = 0; i < 14; i++)
    printf("\n"); // 美化屏幕

  if (players) // 剩余生命值大于0
  {
    printf("                                      "); // 美化屏幕
    printf("Player X %d", players);                   // 显示剩余生命值

    for (i = 0; i < 14; i++) // 美化屏幕
      printf("\n");

    for (int j = 0; j < screen_height; j++)
      for (int i = 0; i < map_length; i++)
        if (map[j][i] == head_value) {
          map[j][i] -= head_value;
          map[j + 1][i] -= body_value;
          map[j + 1][i - 1] -= body_value;
          map[j + 1][i + 1] -= body_value;
          map[j + 2][i] -= body_value;
          map[j + 3][i - 1] -= body_value;
          map[j + 3][i + 1] -= body_value; // 清除屏幕中的其他小人
        }

    if (boss0_exist)
      restart_boss0exist();
    else
      restart_boss0noExist(n);
    /*PlaySound(TEXT("e.wav"), 0, SND_FILENAME);*/
    while (1) {

      Present_time = clock(); // 获取当前时间

      if (Present_time > Trigger_time + 3000)
        system("cls");

      return;
      // 触发陷阱后返回游戏
    }
  }

  else // 剩余生命值为0
  {

    printf("                                      "); // 美化屏幕
    printf("你死了，游戏结束");

    for (i = 0; i < 14; i++)
      printf("\n"); // 美化屏幕
    /*PlaySound(TEXT("e.wav"), 0, SND_FILENAME);*/

    while (1) {
      Present_time = clock(); // 获取当前时间
      if (Present_time > Trigger_time + 3000) {
        eflag1 = 1;
        players = start_players;
        break;
      } // 触发陷阱3000ms后结束游戏
    }
  }
}

void game_finished() {
  int i;
  system("cls");
  for (i = 0; i < 13; i++)
    printf("\n");
  printf("                                        ");
  printf("Boss已被击杀，游戏结束\n");
  printf("\n");
  printf("                                          ");
  printf("Thanks for playing!\n");
  for (i = 0; i < 13; i++)
    printf("\n");
  exit(1);
}

void Trigger() {
  int i, j;
  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == cone1 + body_value || map[j][i] == cone1 + head_value) {
        if (map[j][i] == cone1 + body_value) {
          map[j][i] -= body_value;
        }

        if (map[j][i] == cone1 + head_value) {
          map[j][i] -= head_value;
          map[j + 1][i] -= body_value;
          map[j + 1][i - 1] -= body_value;
          map[j + 1][i + 1] -= body_value;
          map[j + 2][i] -= body_value;
          map[j + 3][i - 1] -= body_value;
          map[j + 3][i + 1] -= body_value;
        }

        /*if (map[j][i] == head_value)
        {
                map[j][i] =- head_value;
                map[j + 1][i] =-body_value;
                map[j + 1][i - 1] =-body_value;
                map[j + 1][i + 1] =-body_value;
                map[j + 2][i] =- body_value;
                map[j + 3][i - 1] =- body_value;
                map[j + 3][i + 1] =- body_value;}*/  //如果头部触碰陷阱，在触碰地点打印小人尸体(有bug)

        player_died(i);
      }

  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == cone2 + body_value || map[j][i] == cone2 + head_value) {
        if (map[j][i] == cone2 + body_value)
          map[j][i] -= body_value;

        if (map[j][i] == cone2 + head_value) {
          map[j][i] -= head_value;
          map[j + 1][i] -= body_value;
          map[j + 1][i - 1] -= body_value;
          map[j + 1][i + 1] -= body_value;
          map[j + 2][i] -= body_value;
          map[j + 3][i - 1] -= body_value;
          map[j + 3][i + 1] -= body_value;
        }

        player_died(i);
      }

  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == boss0_head_value + body_value ||
          map[j][i] == boss0_head_value + head_value ||
          map[j][i] == boss0_body_value + body_value ||
          map[j][i] == boss0_body_value + head_value) {
        if (map[j][i] == boss0_head_value + body_value ||
            map[j][i] == boss0_head_value + head_value) {
          if (map[j][i] == boss0_head_value + body_value)
            map[j][i] -= body_value;

          if (map[j][i] == boss0_head_value + head_value) {
            map[j][i] -= head_value;
            map[j + 1][i] -= body_value;
            map[j + 1][i - 1] -= body_value;
            map[j + 1][i + 1] -= body_value;
            map[j + 2][i] -= body_value;
            map[j + 3][i - 1] -= body_value;
            map[j + 3][i + 1] -= body_value;
          }
        }

        if (map[j][i] == boss0_body_value + body_value ||
            map[j][i] == boss0_body_value + head_value) {
          if (map[j][i] == boss0_body_value + body_value)
            map[j][i] -= body_value;

          if (map[j][i] == boss0_body_value + head_value) {
            map[j][i] -= head_value;
            map[j + 1][i] -= body_value;
            map[j + 1][i - 1] -= body_value;
            map[j + 1][i + 1] -= body_value;
            map[j + 2][i] -= body_value;
            map[j + 3][i - 1] -= body_value;
            map[j + 3][i + 1] -= body_value;
          }
        }

        player_died(i);
      }

  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == item_player_health + body_value ||
          map[j][i] == item_player_health + head_value) {
        if (map[j][i] == item_player_health + body_value)
          map[j][i] -= body_value;
        if (map[j][i] == item_player_health + head_value)
          map[i][i] -= head_value;
        players++;
        eflag = 0;
      }

  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == item_gun + body_value ||
          map[j][i] == item_gun + head_value)
        if (bullet) {
          map[j][i] -= item_gun;
        } else {
          map[j][i] -= item_gun;
          bullet = 5;
        }

  for (j = 0; j < screen_height; j++) {
    if (map[j][map_length - 60] == 100) {
      if (boss0_exist != 1) {
        boss0_exist = 1;
        break;
      }
    }
  }

  if (hp_boss0 <= 0)
    game_finished();
}

