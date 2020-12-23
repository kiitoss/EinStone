#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void create_p1_free_gold(Player_1 *p1, Row *row, int gridX) {
  p1->last_free_gold = MLV_get_time();
  create_new_gold(row, gridX);
}

/* GLOBAL */
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY) {
  this->money = spawner->price + 1000;
  if (this->money >= spawner->price) {
    add_friend_in_row(row, spawner, gridX, gridY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
  this->chosen_friend = -1;
}


/* GLOBAL */
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY) {
  this->money = spawner->price + 1000;
  if (this->money >= spawner->price && row->nb_enemies < MAX_ENEMIES) {
    add_enemy_in_row(row, spawner, posX, posY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
}