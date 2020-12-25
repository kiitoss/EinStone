#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
void p1_create_free_gold(Player_1 *this, Row *row, int gridX, int gridY, Sound_Manager *SM) {
  this->last_free_gold = MLV_get_time();
  create_new_gold(row, gridX, gridY, SM);
}

/* GLOBAL */
void p2_create_free_gold(Player_2 *this) {
  this->money += QTY_FREE_GOLD_P2;
  set_player_money_str(this->money, this->money_str);
  this->last_free_gold = MLV_get_time();
}

/* GLOBAL */
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY) {
  if (this->money >= spawner->price) {
    add_friend_in_row(row, spawner, gridX, gridY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
  this->chosen_friend = -1;
}


/* GLOBAL */
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY) {
  if (this->money >= spawner->price && row->nb_enemies < MAX_ENEMIES) {
    add_enemy_in_row(row, spawner, posX, posY);
    this->money -= spawner->price;
    set_player_money_str(this->money, this->money_str);
  }
}
