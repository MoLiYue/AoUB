#include "level0.h"
#include "all.h"

gameStage::gameStage(int i) : index(i){};

void gameStage::stageSet() {
  if (index == 1) {
    Level_0_asset();
  }
  if (index == 2) {
    Level_1_asset();
  }
  if (index == 3) {
    Level_2_asset();
  }
}
void gameStage::Level_0_asset() {
  int h, l;
  for (l = 25; l <= 35; l++) {
    map[screen_height - 2][l] = cone1;
  }
  for (l = 50; l <= 65; l++) {
    map[screen_height - 12][l] = block1;
    map[screen_height - 2][l] = cone1;
  }
  for (l = 70; l <= 160; l++)
    map[screen_height - 2][l] = cone1;
  for (l = 80; l <= 90; l++) {
    map[screen_height - 9][l] = block1;
  }
  for (l = 90; l < 105; l++) {
    map[2][l] = cone2;
    map[1][l] = block1;
  }
  for (l = 105; l <= 120; l++)
    map[screen_height - 12][l] = block1;
  for (l = 130; l <= 135; l++)
    map[screen_height - 10][l] = block1;
  for (l = 145; l <= 150; l++)
    map[screen_height - 15][l] = block1;
  for (l = 160; l <= 180; l++)
    for (h = 0; h <= 12 - fabs(170 - l); h++)
      map[screen_height - 1 - h][l] = block2;

  for (h = 0; h < screen_height; h++)
    for (l = 181; l < map_length; l++)
      if (map[h][l] == head_value || map[h][l] == body_value)
        Level_0_game_finished();
}

void gameStage::Level_1_asset() {
  int h, l;
  for (l = 0; l < 180; l++) {
    map[4][l] = block1;
    map[5][l] = cone2;
  }

  for (l = 10; l <= 180; l++) {
    if (l % 10)
      map[screen_height - 2][l] = cone1;
    else
      map[screen_height - 2][l] = block1;
  }

  for (l = 20; l <= 25; l++)
    map[screen_height - 8][l] = block1;

  for (l = 35; l <= 37; l++)
    map[screen_height - 6][l] = block1;

  for (l = 50; l <= 55; l++)
    map[screen_height - 9][l] = block1;

  for (l = 70; l <= 80; l++)
    map[screen_height - 8][l] = block1;

  map[screen_height - 9][85] = block1;

  if (eflag)
    map[screen_height - 3][90] = item_player_health;
  else
    map[screen_height - 3][90] = 0;

  for (l = 100; l <= 110; l++) {
    map[screen_height - 2][l] = block1;
  }

  for (l = 103; l <= 107; l++) {
    map[screen_height - 2][l] = cone1;
  }

  for (l = 120; l <= 130; l++) {
    map[screen_height + 118 - l][l] = block1;
    if ((l - 118) % 4 == 0)
      map[screen_height + 118 - l][l] = cone1;
  }

  for (l = 130; l <= 140; l++) {
    map[screen_height - 142 + l][l] = block1;
    if ((l - 162) % 4 == 0)
      map[screen_height - 142 + l][l] = cone1;
  }

  for (h = 1; h <= 15; h++) {
    map[h][165] = block2;
  }
  map[20][165] = cone2;
  map[18][170] = block1;

  for (l = 175; l <= 180; l++)
    map[screen_height - 10][l] = block1;
}
void gameStage::Level_2_asset() {
  int i, j;
  for (i = 20; i <= 30; i++)
    map[screen_height - 2][i] = cone1;
  for (i = 0; i < map_length; i++)
    map[4][i] = block1;
  for (i = 0; i < map_length; i++) {
    if (i <= 240 || i >= 275)
      map[5][i] = cone2;
  }

  for (j = 5; j < screen_height - 10; j++)
    for (i = 35; i < 37; i++)
      map[j][i] = block2;
  for (i = 50; i < 100; i++)
    map[screen_height - 2][i] = block1;
  for (i = 100; i < 107; i++)
    map[screen_height - 2][i] = cone1;
  for (j = 5; j < 12; j++)
    for (i = 105; i < 107; i++)
      map[j][i] = block2;
  for (i = 105; i < 107; i++)
    map[12][i] = cone2;
  for (i = 119; i < 150; i++) {
    if ((i + 1) % 5)
      map[screen_height - 2][i] = block1;
    else
      map[screen_height - 2][i] = cone1;
  }
  for (i = 154; i < 165; i++)
    map[screen_height - 2][i] = cone1;
  if (eflag)
    map[screen_height - 2][165] = item_player_health;
  else
    map[screen_height - 2][165] = 0;
  for (i = 168; i < 180; i++)
    map[screen_height - 2][i] = cone1;
  for (i = 168; i < 180; i++)
    map[screen_height - 8][i] = cone2;
  for (i = 168; i < 180; i++)
    map[screen_height - 9][i] = block1;
  int iNum = 0;
  for (i = 190; i <= 240; i++) {
    if (iNum % 10 == 0) {
      map[screen_height - 7][i] = cone1;
      for (j = screen_height - 2; j > screen_height - 7; j--)
        map[j][i] = block2;
      iNum++;
    } else {
      map[screen_height - 2][i] = cone1;
      iNum++;
    }
  }
  iNum = 0;
  map[screen_height - 3][245] = item_gun;

  for (i = 250; i < 270; i++)
    for (j = screen_height - 2; j >= screen_height - 2 - fabs(260 - i); j--) {
      map[j][i] = cone1;
      if (fabs(260 - i) != 0)
        map[j + 1][i] = block1;
    }

  for (i = 280; i < 300; i++)
    map[screen_height - 5][i] = block1;
  for (i = 310; i < 320; i++)
    map[screen_height - 15][i] = block1;
  // for (j = screen_height - 2; j > 15; j--)
  // map[j] [330] = block1;
  for (i = 336; i < 346; i++)
    map[screen_height - 6][i] = block1;
  for (i = 326; i < 336; i++)
    map[screen_height - 2][i] = cone1;

  for (j = 0; j < screen_height; j++) {
    if (map[j][map_length - 60] == 100) {
      if (boss0_exist != 1) {
        boss0_exist = 1;
        break;
      }
    }
  }

  if (hp_boss0 <= 0)
    Level_1_game_finished();
}

void gameStage::restart_boss0noExist(
    int i) // 地图中有boss存在，死亡后复活在死亡坐标前最近的安全地点
{

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
void gameStage::restart_boss0exist() // 地图中无boss，死亡后复活在游戏初始位置
{

  map[head_x][head_y] = head_value;
  map[head_x + 1][head_y] = body_value;
  map[head_x + 1][head_y - 1] = body_value;
  map[head_x + 1][head_y + 1] = body_value;
  map[head_x + 2][head_y] = body_value;
  map[head_x + 3][head_y - 1] = body_value;
  map[head_x + 3][head_y + 1] = body_value; // 初始化小人位置
}

void gameStage::player_died(int n) // 死亡判定函数
{

  int i, Trigger_time = clock(); // 触碰陷阱（cone）的时间
  int Present_time = 0;          // 定义变量“当前时间”

  players--; // 生命值-1s

  // 清屏，切换到死亡界面
  clean_screen();
  bullet = 0;

  for (i = 0; i < 14; i++)
    cout << "\n"; // 美化屏幕

  if (players) // 剩余生命值大于0
  {
    cout << "                                      "; // 美化屏幕
    cout << "Player X " << players;                   // 显示剩余生命值

    for (i = 0; i < 14; i++) // 美化屏幕
      cout << "\n";

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
    // chongsheditu
    if (index == 1) {
      Level_0_asset();
    } else if (index == 2) {
      Level_1_asset();
    } else if (index == 3) {
      Level_2_asset();
    }
    if (boss0_exist)
      restart_boss0exist();
    else
      restart_boss0noExist(n);
    /*PlaySound(TEXT("e.wav"), 0, SND_FILENAME);*/
    while (1) {

      Present_time = clock(); // 获取当前时间

      if (Present_time > Trigger_time + 3000)
        clean_screen();

      return;
      // 触发陷阱后返回游戏
    }
  }

  else // 剩余生命值为0
  {

    cout << "                                      "; // 美化屏幕
    cout << "你死了，游戏结束";

    for (i = 0; i < 14; i++)
      cout << "\n"; // 美化屏幕
    /*PlaySound(TEXT("e.wav"), 0, SND_FILENAME);*/
    for (int j = 0; j < screen_height; j++)
      for (i = 0; i < map_length; i++)
        map[j][i] = 0;

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

void gameStage::Level_0_game_finished() {
  int i, Present_time, Trigger_time = 0;
  clean_screen();
  for (i = 0; i < 13; i++)
    cout << "\n";
  cout << "                                           ";
  cout << "Stage Clear!" << endl;
  cout << "\n";
  cout << "                                          ";
  cout << "Thanks for playing!" << endl;
  for (i = 0; i < 13; i++)
    cout << "\n";
  for (int j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      map[j][i] = 0;
  Trigger_time = clock();
  while (1) {
    Present_time = clock(); // 获取当前时间
    if (Present_time > Trigger_time + 3000) {
      eflag1 = 1;
      players = start_players;
      break;
    } // 触发陷阱3000ms后结束游戏
  }
  // exit(1);
}

void gameStage::Level_1_game_finished() {
  int i, Present_time, Trigger_time = 0;
  clean_screen();
  for (i = 0; i < 13; i++)
    cout << "\n";
  cout << "                                        ";
  cout << "Boss已被击杀，游戏结束" << endl;
  cout << "\n";
  cout << "                                          ";
  cout << "Thanks for playing!" << endl;
  for (i = 0; i < 13; i++)
    cout << "\n";
  for (int j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      map[j][i] = 0;
  Trigger_time = clock();
  while (1) {
    Present_time = clock(); // 获取当前时间
    if (Present_time > Trigger_time + 3000) {
      // eflag1 = 1;
      players = start_players;
      break;
    } // 触发陷阱3000ms后结束游戏
  }
  exit(1);
}

void gameStage::Trigger() {
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
      if (map[j][i] == item_player_health + body_value) {
        if (map[j][i] == item_player_health + body_value)
          map[j][i] -= body_value;

        players++;
        eflag = 0;
      }

  for (j = 0; j < screen_height; j++)
    for (i = 0; i < map_length; i++)
      if (map[j][i] == item_gun + body_value ||
          map[j][i] == item_gun + head_value)
        if (bullet) {
          // map[j][i] -= item_gun;
        } else {
          // map[j][i] -= item_gun;
          bullet = 5;
        }

  if (index == 1 || index == 2) {
    for (int h = 0; h < screen_height; h++)
      for (int l = 183; l < map_length; l++)
        if (map[h][l] == head_value || map[h][l] == body_value)
          Level_0_game_finished();
  }

  if (index == 3) {
    for (j = 0; j < screen_height; j++) {
      if (map[j][map_length - 60] == 100) {
        if (boss0_exist != 1) {
          boss0_exist = 1;
          break;
        }
      }
    }

    if (hp_boss0 <= 0)
      Level_1_game_finished();
  }
}
