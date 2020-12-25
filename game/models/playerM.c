#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void set_player_money_str(int money, char money_str[10]) {
  sprintf(money_str, "%d", money);
}

/* GLOBAL */
void set_player_life_str(int life, char life_str[10]) {
  sprintf(life_str, "%d", life);
}
/* GLOBAL */
void p1_add_gold(Player_1 *this, int gold) {
  this->money += gold;
  set_player_money_str(this->money, this->money_str);
}

/* GLOBAL */
Player_1 init_p1() {
  Player_1 p1;
  p1.chosen_friend = -1;
  p1.money = 10000;
  p1.last_free_gold = MLV_get_time();
  p1.score = 0;
  set_player_money_str(p1.money, p1.money_str);
  p1.life = 5;
  set_player_life_str(p1.life, p1.life_str);
  p1.is_deleting = false;
  return p1;
}

/* GLOBAL */
Player_2 init_p2() {
  Player_2 p2;
  p2.chosen_row = 0;
  p2.chosen_enemy = 0;
  p2.money = 50;
  p2.last_free_gold = MLV_get_time();
  p2.score = 0;
  set_player_money_str(p2.money, p2.money_str);
  return p2;
}
