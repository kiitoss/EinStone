#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void set_player_money_str(int money, char money_str[10]) {
  sprintf(money_str, "%d", money);
}


/* GLOBAL */
Player_1 init_p1() {
  Player_1 p1;
  p1.chosen_friend = -1;
  p1.money = 0;
  p1.last_free_gold = MLV_get_time();
  p1.delay_free_gold = 1000;
  p1.score = 0;
  set_player_money_str(p1.money, p1.money_str);
  return p1;
}

/* GLOBAL */
Player_2 init_p2() {
  Player_2 p2;
  p2.chosen_row = 0;
  p2.chosen_enemy = 0;
  p2.money = 0;
  p2.last_free_gold = MLV_get_time();
  p2.delay_free_gold = 1000;
  p2.score = 0;
  set_player_money_str(p2.money, p2.money_str);
  return p2;
}
