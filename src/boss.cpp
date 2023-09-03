#include "all.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int boss::check_jump() {
  maxj = 4;
  for (int i = -5; i <= 5; i++) {
    for (int j = 0; j <= 3; j++) {
      if (map[x_boss0 - 1 - j][y_boss0 + i] != 0)
        if (j < maxj)
          maxj = j;
    }
  }
  return maxj;
}
int boss::check_drop() {
  maxd = 2;
  for (int i = -5; i <= 5; i++) {
    for (int j = 0; j <= 1; j++) {
      if (map[x_boss0 + 6 + j][y_boss0 + i] != 0)
        if (j < maxd)
          maxd = j;
    }
  }
  return maxd;
}
int boss::check_l() {

  for (int i = 0; i <= 5; i++) {
    if (map[x_boss0 + i][y_boss0 - 6] == 0 ||
        map[x_boss0 + i][y_boss0 - 6] == body_value ||
        map[x_boss0 + i][y_boss0 - 6] == head_value) {

    } else {
      return 0;
    }
  }
  return 1;
}
int boss::check_r() {

  for (int i = 0; i <= 5; i++) {
    if (map[x_boss0 + i][y_boss0 + 6] == 0 ||
        map[x_boss0 + i][y_boss0 + 6] == body_value ||
        map[x_boss0 + i][y_boss0 + 6] == head_value) {
    } else {
      return 0;
    }
  }
  return 1;
}
void boss::move_l() {
  map[x_boss0][y_boss0] -= boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
  //
  y_boss0 -= 1;
  map[x_boss0][y_boss0] += boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
  map[x_boss0 + 5][y_boss0] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
}
void boss::move_r() {
  map[x_boss0][y_boss0] -= boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
  //
  y_boss0 += 1;
  map[x_boss0][y_boss0] += boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
  map[x_boss0 + 5][y_boss0] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
}
void boss::drop() {
  map[x_boss0][y_boss0] -= boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
  //
  x_boss0 += 1;
  map[x_boss0][y_boss0] += boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
  map[x_boss0 + 5][y_boss0] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
}
void boss::jump() {
  map[x_boss0][y_boss0] -= boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 1][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0] -= boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
  //
  x_boss0 -= 1;
  map[x_boss0][y_boss0] += boss0_head_value;
  map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 1][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
  map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
  map[x_boss0 + 5][y_boss0] += boss0_body_value;
  map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
}
void boss::boss_ai() {
  if (boss0_move != '1') {
    boss0_move = '0';
    if (bullet == 0) // 无子弹
    {
      if (x - y_boss0 > 25) {
        if (check_r() != 0) {
          // boss0_move = 'd';
          move_r();
        } else {
          if (check_jump() != 0) {
            for (int p = 1; p <= check_jump(); p++) {
              jump();
            }
          } else {
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          }
        }
      } else if (x - y_boss0 < -25) {
        if (check_l() != 0) {
          // boss0_move = 'a';
          move_l();
        } else {
          if (check_jump() != 0) {
            for (int p = 1; p <= check_jump(); p++) {
              jump();
            }
          } else {
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          }
        }
      } else {
        if (x - y_boss0 > 0) {
          if (check_r() != 0) {
            if (y - x_boss0 < 6 && check_jump() != 0) {
              /*boss0_move = 'd';*/
              move_r();
              for (int p = 1; p < check_jump(); p++) {
                jump();
              }
            } else {
              /*boss0_move = 'd';*/
              move_r();
            }
          } else {
            if (check_jump() != 0) {
              for (int p = 1; p <= check_jump(); p++) {
                jump();
              }
            } else {
              for (int p = 1; p <= check_drop(); p++) {
                drop();
              }
            }
          }
        } else {
          if (check_l() != 0) {
            if (y - x_boss0 < 6 && check_jump() != 0) {
              /*boss0_move = 'a';*/

              move_l();
              for (int p = 1; p <= check_jump(); p++) {
                jump();
              }

            } else {
              /*boss0_move = 'a';*/
              move_l();
            }
          } else {

            if (check_jump() != 0) {
              jump();

              for (int p = 1; p <= check_jump() - 1; p++) {
                jump();
                move_l();
              }

            } else {
              for (int p = 1; p <= check_drop(); p++) {
                drop();
              }
            }
          }
        }
      }
    } else // 有子弹
    {
      if (x - y_boss0 > 0 && x - y_boss0 < 25) {
        if (check_jump() != 0) {
          if (y_boss0 <= 8) // gai
          {
            for (int p = 1; p <= check_jump(); p++) {
              jump();
            }
          } else {
            if (check_l() != 0) {
              move_l();
              for (int p = 1; p <= check_jump(); p++) {
                jump();
              }
              /*boss0_move = 'a';*/
            } else {
              for (int p = 1; p <= check_drop(); p++) {
                drop();
              }
            }
          }
        } else {
          if (check_l() != 0) {
            /*boss0_move = 'a';*/
            move_l();
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          } else {
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          }
        }
      } else if (x - y_boss0 < 0 && x - y_boss0 > -25) {
        if (check_jump() != 0) {
          if (y_boss0 >= map_length - 8) // gai
          {
            for (int p = 1; p <= check_jump(); p++) {
              jump();
            }
          } else {
            if (check_r() != 0) {
              move_r();
              for (int p = 1; p <= check_jump(); p++) {
                jump();
              }
              /*boss0_move = 'd';*/
            } else {
              for (int p = 1; p <= check_drop(); p++) {
                drop();
              }
            }
          }
        } else {
          if (check_r() != 0) {
            /*boss0_move = 'r';*/
            move_r();
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          } else {
            for (int p = 1; p <= check_drop(); p++) {
              drop();
            }
          }
        }
      }
    }
  }
}
void boss::boss_asset() {

  if (boss0_exist == 1) {
    boss_ai();

    if (boss0_move == '1') {
      x_boss0 = boss0_x;
      y_boss0 = boss0_y;
      map[x_boss0][y_boss0] = boss0_head_value;
      map[x_boss0 + 1][y_boss0 - 1] = boss0_body_value;
      map[x_boss0 + 1][y_boss0 + 1] = boss0_body_value;
      map[x_boss0 + 1][y_boss0] = boss0_body_value;
      map[x_boss0 + 2][y_boss0 - 2] = boss0_body_value;
      map[x_boss0 + 2][y_boss0 - 1] = boss0_body_value;
      map[x_boss0 + 2][y_boss0] = boss0_body_value;
      map[x_boss0 + 2][y_boss0 + 1] = boss0_body_value;
      map[x_boss0 + 2][y_boss0 + 2] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 - 3] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 - 2] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 - 1] = boss0_body_value;
      map[x_boss0 + 3][y_boss0] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 + 1] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 + 2] = boss0_body_value;
      map[x_boss0 + 3][y_boss0 + 3] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 - 4] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 - 3] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 - 2] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 - 1] = boss0_body_value;
      map[x_boss0 + 4][y_boss0] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 + 1] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 + 2] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 + 3] = boss0_body_value;
      map[x_boss0 + 4][y_boss0 + 4] = boss0_body_value;
      map[x_boss0 + 5][y_boss0 - 5] = boss0_body_value;
      map[x_boss0 + 5][y_boss0] = boss0_body_value;
      map[x_boss0 + 5][y_boss0 + 5] = boss0_body_value;
      boss0_move = '0';
    }
    // else if (boss0_move == 'a')
    //{
    //	map[x_boss0][y_boss0] -= boss0_head_value;
    //	map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 1][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
    //	//
    //	y_boss0 -= 1;
    //	map[x_boss0][y_boss0] += boss0_head_value;
    //	map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 1][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
    // }
    // else if (boss0_move == 'd')
    //{
    //	map[x_boss0][y_boss0] -= boss0_head_value;
    //	map[x_boss0 + 1][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 1][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 1][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 3] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 4] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 2] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 1] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 1] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 2] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 3] -= boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 4] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 - 5] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0] -= boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 + 5] -= boss0_body_value;
    //	//
    //	y_boss0 += 1;
    //	map[x_boss0][y_boss0] += boss0_head_value;
    //	map[x_boss0 + 1][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 1][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 1][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 2][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 3] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 3][y_boss0 + 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 4] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 2] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 - 1] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 1] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 2] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 3] += boss0_body_value;
    //	map[x_boss0 + 4][y_boss0 + 4] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 - 5] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0] += boss0_body_value;
    //	map[x_boss0 + 5][y_boss0 + 5] += boss0_body_value;
    // }
    for (int p = 1; p <= check_drop(); p++) {
      drop();
    }
  }
}
