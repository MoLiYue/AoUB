// ConsoleApplication7.cpp: 定义控制台应用程序的入口点。
//
#include "functions.h"
// #include <Windows.h>
#include "all.h"
#include <time.h>
// #include"level0.h"

// extern int screen[screen_height][screen_length];
// extern int player[screen_height][screen_length];

int main() {
  memset(map, 0, sizeof(map));
  while (1) {
    menu_final();
    if (flag3)
      return 0;

    clean_screen();

    player_creator(map); // 初始小人位置

    // 打印屏幕
    timenow1 = ((clock() / speed) + 1) * speed;
    eflag = 1;

    while (1) {
      main_process();
      if (eflag1) {
        eflag1 = 0;
        break;
      }
    }
  }
}
