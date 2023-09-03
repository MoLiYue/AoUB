#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN64)
#include <conio.h>
#include <windows.h>
#else
#include <curses.h>
#endif

#include "all.h"
#include "functions.h"
#include "level0.h"
#define A 30
#define B 40
using namespace std;

class ChoseMap {
protected:
  char *p;
  int index;
  gameStage map;

public:
  ChoseMap();
  ChoseMap(char *n);
  void showmap(int);
  void SetUpmap(int i);
  ~ChoseMap() {
    if (p)
      delete[] p;
  };
};
void ChoseMap::SetUpmap(int i) {
  gameStage copy(i);
  map = copy;
  map.stageSet();
}
ChoseMap::ChoseMap(char *n) : p(n) {
  if (n) {
    p = new char[strlen(n) + 1];
    memcpy(p, n, strlen(n) + 1);
  } else {
    p = new char[8];
    memcpy(p, "no map", 8);
  }
}
ChoseMap::ChoseMap() : p(NULL) {
  p = new char[8];
  memcpy(p, "no map", 8);
}
void ChoseMap::showmap(int j) {
  index = j;
  int i;
  for (i = 6 + index; i < screen_height; i++) {
    memcpy(*(mapchoose_view + 6 + index) + 40, p, strlen(p) + 1);
  }
}
int point();
void point_move(int b);
const char *pointer = "--->";
void menu_getch_part();
char ch3 = '0';
char ch4 = '0';
int flag1 = 0; // 判断是否更改pointer
int flag2 = 1; // 判断是否退出getch模式
// int flag3 = 0;
// 判断是否推出游戏
int flag4 = 0; // 判断是否退出getch模式
int flag5 = 0; // 判断是否二次及以后输出menu
void mapchoose_view0() {
  int i, j;
  clean_screen();
  for (int j = 0; j < screen_height; j++) {
    for (int i = 0; i < screen_length; i++) {
      mapchoose_view[j][i] = ' ';
    }
  }
  memcpy(*(mapchoose_view + 5) + 40,
         "Choose Map: ", strlen("Choose Map: ") + 1);
  memcpy(*(mapchoose_view + 15) + 40,
         "Input Number: ", strlen("Input Number: ") + 1);
}
void mapChoose0() // 首次输出menu
{
  int i, j;
  clean_screen();
  for (j = 0; j < screen_height; j++) {
    for (i = 0; i < screen_length; i++) {
      cout << mapchoose_view[j][i];
    }
  }
}

void menu0() // 首次输出menu
{
  int i, j;
  clean_screen();
  for (j = 0; j < screen_height; j++) {
    for (i = 0; i < screen_length; i++) {
      cout << menu_view[j][i];
    }
  }
}
void help() // 二次及以后输出menu
{
  int i, j;
  clean_screen();
  for (j = 0; j < screen_height; j++) {
    for (i = 0; i < screen_length; i++) {
      cout << help_view[j][i];
    }
  }
}
int point() // 判断指向位置
{
  int i;
  for (i = 13;; i++) {
    if (menu_view[i][40] == '-')
      break;
  }
  return i;
}
void point_move(int b) // a为当前所指位置,b为下一位置
{
  int i, k, a;
  a = point();
  for (k = 40, i = 0; k < 40 + 4; k++, i++) {
    menu_view[a][k] = ' ';
  }
  for (k = 40, i = 0; k < 40 + 4; k++, i++) {
    menu_view[b][k] = pointer[i];
  }
}
void menu_input() {
  const char *a = "Adventure of QueDe Brother";
  const char *b = "start the game";
  const char *c = "quit the game";
  const char *e = "press -> to enter";
  const char *f = "help";
  // char *pa, *pb, *pc;
  for (int j = 0; j < screen_height; j++) {
    for (int i = 0; i < screen_length; i++) {
      menu_view[j][i] = ' ';
    }
  }
  memcpy(*(menu_view + 10) + 40, a,
         strlen(a) + 1); //"Adventure of QueDe Brother"
  memcpy(*(menu_view + 13) + 45, b, strlen(b) + 1); //"start the game"
  memcpy(*(menu_view + 14) + 49, f, strlen(f) + 1); //"help"
  memcpy(*(menu_view + 15) + 45, c, strlen(c) + 1); //"quit the game"
  memcpy(*(menu_view + 13) + 40, pointer, strlen(pointer) + 1); //"--->"
  memcpy(*(menu_view + 20) + 43, e, strlen(e) + 1); //"press -> to enter"
}
void help_input() {
  const char *e = "press <- to go back";
  const char *f = "help";
  const char *instruction1 = "Kill the boss to finish the game.";
  const char *instruction2 =
      "Operation: Tap direction key to control the game role.";
  const char *instruction6 = "Item :";
  const char *instruction3 = "'*' Player health+1        '?' gun";
  const char *instruction5 =
      "Hit <q> to shoot left       hit <e> to shoot right";
  const char *instruction7 = "Terra:";
  const char *instruction4 = "'='&'|' Block           '^'&'v' cone";

  for (int j = 0; j < screen_height; j++) {
    for (int i = 0; i < screen_length; i++) {
      help_view[j][i] = ' ';
    }
  }
  memcpy(*(help_view + 5) + 49, f, strlen(f) + 1); //"help"
  memcpy(*(help_view + 11) + A, instruction1,
         strlen(instruction1) + 1); //"Kill the boss to finish the game."
  memcpy(*(help_view + 12) + A, instruction2,
         strlen(instruction2) +
             1); //"Operation: Tap direction key to control the game role."
  memcpy(*(help_view + 13) + A, instruction6,
         strlen(instruction6) + 1); //"Item :"
  memcpy(*(help_view + 14) + B, instruction3,
         strlen(instruction3) + 1); //"'*' Player health+1		'?' gun"
  memcpy(*(help_view + 15) + B, instruction5,
         strlen(instruction5) +
             1); //"Hit<q> to shoot left		hit<e> to shoot right"
  memcpy(*(help_view + 16) + A, instruction7,
         strlen(instruction7) + 1); //"Terra:"
  memcpy(*(help_view + 17) + B, instruction4,
         strlen(instruction4) +
             1); //"'='&'|' Block			'^'&'v' cone"
  memcpy(*(help_view + 20) + 42, e, strlen(e) + 1); //"press <- to go back"
}
void menu_getch_part() {
#if defined(_WIN64)
  if (_kbhit()) // 判断是否输入按键
#else
  if(true)
#endif
  {
    flag2 = 1;
#if defined (_WIN64)
    ch3 = _getch();
#else
    ch3 = getch();
#endif
    if (ch3 == -32) // 是否为方向键
    {
#if defined (_WIN64)
      ch4 = _getch();
#else
      ch4 = getch();
#endif
      switch (ch4) {
      case 'H':
        if (point() <= 15 && point() > 13) {
          point_move(point() - 1);
          flag1 = 1;
        }
        break;
      case 'M':
        flag2 = 0;
        if (point() == 14)
          flag5 = 1;
        break; // 右
      case 'P':
        if (point() < 15 && point() >= 13) {
          point_move(point() + 1);
          flag1 = 1;
        }
        break; // 下
      default:
        break; // 其他情况(越界)
      }
    }
  }
}
void help_getch_part() {

#if defined(_WIN64)
  if (_kbhit()) // 判断是否输入按键
#else
  if(true)
#endif
  {
    flag2 = 1;
#if defined (_WIN64)
    ch3 = _getch();
#else
    ch3 = getch();
#endif
    if (ch3 == -32) // 是否为方向键
    {
#if defined (_WIN64)
      ch4 = _getch();
#else
      ch4 = getch();
#endif
      switch (ch4) {
      case 'K':
        flag4 = 1;
        break;               // 左
        /*default:  break;*/ // 其他情况(越界)
      }
    }
  }
}
void menu_final() {
  help_input();
  menu_input();
part1:
  menu0();
  ChoseMap map1((char *)"Map 1");
  ChoseMap map2((char *)"Map 2");
  ChoseMap map3((char *)"Map 3");
  while (1) {
    menu_getch_part();
    if (flag1) {
      menu0();
      flag1 = 0;
    }
    if (!flag2)
      break;
  }

  if (point() == 13) {
    mapchoose_view0();
    map1.showmap(1);
    map2.showmap(2);
    map3.showmap(3);
    mapChoose0();
    cin >> aa;
    if (aa == 1)
      map1.SetUpmap(1);
    else if (aa == 2)
      map2.SetUpmap(2);
    else if (aa == 3)
      map3.SetUpmap(3);
    else
      flag3 = 1;
  }
  flag2 = 1;
  if (point() == 15)
    flag3 = 1;
  if (point() == 14) {
    flag5 = 1;
    do {
      while (1) {
        help_getch_part();
        if (flag5) {
          help();
          flag5 = 0;
        }
        if (flag4)
          break;
      }
    } while (flag4 == 0);
    flag4 = 0;
    goto part1;
  }
}
