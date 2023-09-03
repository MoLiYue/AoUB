// getAndmoving.cpp: 定义控制台应用程序的入口点。
#include <stdlib.h>

#include "all.h"
#include "functions.h"
#include "level0.h"

#if defined(_WIN64)
#include <conio.h> //console io
#include <windows.h>
#else
#include <curses.h>
#endif

/*
键盘的方向键居然有两个码值，所以要读取两次，而上下左右的第一个码值都是一样的，只有第二个有区别。
码值表如下：

上   -32 0xffffffe0 72 ascii码对应为 H
下   -32 0xffffffe0 80               P
左   -32 0xffffffe0 75               K
右   -32 0xffffffe0 77               M

*/
getMoving::getMoving(int i) : start(i) {}
void getMoving::getch_part() {

  for (int s = 0; s < screen_height; s++) {
    for (int k = 0; k < map_length; k++) // 通过头部的特殊值定位小人头部位置
    {
      if (map[s][k] == head_value) {
        y = s; // 行序数对应纵坐标
        x = k; // 列序数对应横坐标
      }
    }
  }
#if defined(_WIN64)
  if (_kbhit()) // 判断是否输入按键
#else
  if (true)
#endif
  {
#if defined(_WIN64)
    ch1 = _getch();
#else
    ch1 = getch();
#endif
    if (ch1 == -32) // 是否为方向键
    {
#if defined(_WIN64)
      ch2 = _getch();
#else
      ch2 = getch();
#endif
      switch (ch2) {
      case 'H':
        if (y - jump_height <= 1) {
          direction = 'p';
        } else
          direction = 'w';
        break; // 上

      case 'K':
        if ((x - move_left <= 0) || (map[y][x - move_left] == block1) ||
            (map[y][x - move_left] == block2)) {
          direction = 'o';
        } else
          direction = 'a';
        break; // 左

      case 'M':
        if ((x + move_right >= 899) || (map[y][x + move_right] == block1) ||
            (map[y][x + move_right] == block2)) {
          direction = 'o';
        } else
          direction = 'd';
        break; // 右
               // case 'P': direction = 's'; break; //方向下键暂时不要
      default:
        direction = 'o';
        break; // 其他情况(越界)
      }
    } else {
      if (ch1 == 'e' && bullet > 0) {
        bullet--;
        attack_l();
        ch1 = 0;
      } else if (ch1 == 'q' && bullet > 0) {
        bullet--;
        attack_r();
        ch1 = 0;
      }
    }
  } else {
    if (prev_direction == 'w') {
      direction = 'x';
      prev_direction = direction;
    }
  }
}

void getMoving::moving_part(int map[screen_height][map_length]) {
  if ((prev_direction == 'w' || prev_direction == 'x' ||
       prev_direction == 'k' || prev_direction == 'p') &&
      (y + 1 <= 21)) {
    clean_screen();
    // 新:向上跳会越界(情况'p') 和
    // 若前一个操作为跳跃(情况'w')或跳跃后不输入按键(情况'x')
    // 或跳跃后左右移动(情况'k')且下落后不会越界时,执行下落画面
    check_height_down();
    if (mark_down) {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y + dist_down][x] += head_value;
      map[y + dist_down + 1][x] += body_value;
      map[y + dist_down + 1][x - 1] += body_value;
      map[y + dist_down + 1][x + 1] += body_value;
      map[y + dist_down + 2][x] += body_value;
      map[y + dist_down + 3][x - 1] += body_value;
      map[y + dist_down + 3][x + 1] += body_value;
    } else {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y + drop_height][x] += head_value;
      map[y + drop_height + 1][x] += body_value;
      map[y + drop_height + 1][x - 1] += body_value;
      map[y + drop_height + 1][x + 1] += body_value;
      map[y + drop_height + 2][x] += body_value;
      map[y + drop_height + 3][x - 1] += body_value;
      map[y + drop_height + 3][x + 1] += body_value;
    }
    // screen_creator(screen, player);			//打印下落画面

    for (int s = 0; s < screen_height; s++) {
      for (int k = 0; k < map_length; k++) // 通过头部的特殊值定位小人头部位置
      {
        if (map[s][k] == head_value) {
          y = s; // 行序数对应纵坐标
          x = k; // 列序数对应横坐标-----------------------新:重新定位下落一帧后小人位置
        }
      }
    }
  }

  switch (direction) {
    // 方向键上 且不越界
  case 'w':
    clean_screen();
    check_height_up();
    if (mark_jump) {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y - dist_jump][x] += head_value;
      map[y - dist_jump + 1][x] += body_value;
      map[y - dist_jump + 1][x - 1] += body_value;
      map[y - dist_jump + 1][x + 1] += body_value;
      map[y - dist_jump + 2][x] += body_value;
      map[y - dist_jump + 3][x - 1] += body_value;
      map[y - dist_jump + 3][x + 1] += body_value;
    } else {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y - jump_height][x] += head_value;
      map[y - jump_height + 1][x] += body_value;
      map[y - jump_height + 1][x - 1] += body_value;
      map[y - jump_height + 1][x + 1] += body_value;
      map[y - jump_height + 2][x] += body_value;
      map[y - jump_height + 3][x - 1] += body_value;
      map[y - jump_height + 3][x + 1] += body_value;
    }
    prev_direction = direction; //------新:记录当前操作方向
                                // screen_creator(screen, player); break;
    break;
  case 'a': // 方向键左且不越界
    clean_screen();
    if ((map[y + 1][x - 1 - move_left] == 500) ||
        (map[y + 1][x - 1 - move_left] == 505) ||
        (map[y + 3][x - 1 - move_left] == 500) ||
        (map[y + 3][x - 1 - move_left] == 505)) {
      // 保持位置不变
    } else {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y][x - move_left] += head_value;
      map[y + 1][x - move_left] += body_value;
      map[y + 1][x - move_left - 1] += body_value;
      map[y + 1][x - move_left + 1] += body_value;
      map[y + 2][x - move_left] += body_value;
      map[y + 3][x - move_left - 1] += body_value;
      map[y + 3][x - move_left + 1] += body_value;
    }

    if (prev_direction == 'w' || prev_direction == 'x' ||
        prev_direction ==
            'k') // 新:若前一个操作为跳跃(方向键上)或跳跃后无新按键输入,使pre_direction
                 // 的值变为k
    {            // 对应跳跃后仍左右移动的情况
      prev_direction = 'k';
    }

    direction =
        'p'; // 新:将按键判断与打印动作拆分在时间判定入口两侧后,左右移动后要将direction的值重置为无意义的i
             // 否则若无后续按键输入小人会一直保持这个方向运动(而且会穿屏)但会使跳跃后左右移动小人无法下落,二次修改改为'p'
    break;
  case 'd':
    clean_screen();
    if ((map[y + 1][x + 1 + move_right] == 500) ||
        (map[y + 1][x + 1 + move_right] == 505) ||
        (map[y + 3][x + 1 + move_right] == 500) ||
        (map[y + 3][x + 1 + move_right] == 505)) {
      // 保持位置不变
    } else {
      map[y][x] -= head_value;
      map[y + 1][x] -= body_value;
      map[y + 1][x - 1] -= body_value;
      map[y + 1][x + 1] -= body_value;
      map[y + 2][x] -= body_value;
      map[y + 3][x - 1] -= body_value;
      map[y + 3][x + 1] -= body_value;

      map[y][x + move_right] += head_value;
      map[y + 1][x + move_right] += body_value;
      map[y + 1][x + move_right - 1] += body_value;
      map[y + 1][x + move_right + 1] += body_value;
      map[y + 2][x + move_right] += body_value;
      map[y + 3][x + move_right - 1] += body_value;
      map[y + 3][x + move_right + 1] += body_value;
    }
    if (prev_direction == 'w' || prev_direction == 'x' ||
        prev_direction ==
            'k') // 新:若前一个操作为跳跃(方向键上)或跳跃后无新按键输入,使pre_direction
                 // 的值变为k
    {            // 对应跳跃后仍左右移动的情况
      prev_direction = 'k';
    }
    direction = 'p';
    break;
  case 'p':
    prev_direction = direction;
  default:
    clean_screen();             // 其他情况(越界)保持小人位置不变
    prev_direction = direction; //------新:记录当前操作方向
    break;
  }
}

void getMoving::check_height_up(void) {
  mark_jump = 0;
  dist_jump = 0;
  for (int i = 1; i <= jump_height; i++) {
    if ((map[y - i][x] == block1) || (map[y - i][x] == block2)) {
      dist_jump = i - 1;
      mark_jump = 1;
      return;
    }
  }
  for (int i = 1; i <= jump_height; i++) {
    if ((map[y + 1 - i][x + 1] == block1) ||
        (map[y + 1 - i][x + 1] == block2) ||
        (map[y + 1 - i][x - 1] == block1) ||
        (map[y + 1 - i][x - 1] == block2)) {
      dist_jump = i - 1;
      mark_jump = 1;
      return;
    }
  }
}

void getMoving::check_height_down() {
  mark_down = 0;
  dist_down = 0;
  for (int i = 1; i <= drop_height; i++) {
    if ((map[y + 3 + i][x + 1] == block1) ||
        (map[y + 3 + i][x + 1] == block2) || (map[y + 3 + i][x + 1] == EDGE) ||
        (map[y + 3 + i][x - 1] == EDGE) || (map[y + 3 + i][x - 1] == block1) ||
        (map[y + 3 + i][x - 1] == block2)) {
      dist_down = i - 1;
      mark_down = 1;
      return;
    }
  }
}

void getMoving::attack_l() {
  for (int i = 0; i <= 24; i++) {
    if (x + 2 < map_length && x + 2 > 0) {
      if (map[y + 1][x + 2 + i] == boss0_head_value) {
        hp_boss0 -= 5;

        break;
      } else if (map[y + 1][x + 2 + i] == boss0_body_value) {
        hp_boss0 -= 2;

        break;
      } else if (map[y + 1][x + 2 + i] == 0) {
      } else {
        break;
      }
    } else {
      break;
    }
  }
}

void getMoving::attack_r() {
  for (int i = 0; i <= 24; i++) {
    if (x + 2 < map_length && x + 2 > 0) {
      if (map[y + 1][x - 2 - i] == boss0_head_value) {
        hp_boss0 -= 5;
        break;
      } else if (map[y + 1][x - 2 - i] == boss0_body_value) {
        hp_boss0 -= 2;
        break;
      } else if (map[y + 1][x - 2 - i] == 0) {
      } else {
        break;
      }
    } else {
      break;
    }
  }
}
