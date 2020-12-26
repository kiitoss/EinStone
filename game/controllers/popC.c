#include "../../mainHeader.h"
#include "../makhead.h"





/* Retourne un nouveau tir. */
/* GLOBAL */
Shot get_new_shot(int posX, int posY, int rectsize, int attack) {
  Shot s;
  s.posX = posX;
  s.posY = posY;
  s.attack = attack;
  s.speed = (rectsize/20 == 0) ? 1 : rectsize/30;
  return s;
}





/* Retourne vrai si le joueur a cliqué sur la pièce d'or. */
/* GLOBAL */
bool is_clicked_gold(Gold *this, int mouseX, int mouseY) {
  bool is_clicked = false;
  if (mouseX >= this->centerX - this->radius/2 && mouseX <= this->centerX + this->radius/2 && mouseY >= this->centerY - this->radius/2 && mouseY <= this->centerY + this->radius/2) {
    is_clicked = true;
  }
  return is_clicked;
}





/* Retourne une nouvelle pièce d'or. */
/* GLOBAL */
Gold get_new_gold(int centerX, int centerY, int rectsize) {
  Gold g;
  g.centerX = centerX;
  g.centerY = centerY;
  g.time_left = 10000;
  g.radius = 1;
  g.max_radius = rectsize/2;
  g.value = 10;
  return g;
}




/* Met à jour une pièce d'or du terrain. */
/* GLOBAL */
void update_gold(Gold *this) {
  if (this->radius < this->max_radius) {
    this->radius += 10;
  }
  this->time_left -= DELAY_REFRESH;
}





/* Met à jour un tir allié. */
/* GLOBAL */
void move_shot(Shot *this) {
  this->posX += this->speed;
}





/* Créé de l'or dans une position aléatoire d'un carré du terrain. */
/* GLOBAL */
void create_new_gold(Row *row, int gridX, int gridY, Sound_Manager *SM) {
  if (row->nb_golds >= MAX_GOLDS) {return;}

  play_sound(SM, &SM->gold);
  
  row->golds[row->nb_golds++] = get_new_gold((rand() % row->rectsize) + gridX * row->rectsize,
					     (rand() % row->rectsize) + gridY * row->rectsize,
					     row->rectsize);
}





/* Créé un tir allié. */
/* GLOBAL */
void create_new_shot(Row *row, int gridX, int gridY, int attack, Sound_Manager *SM) {
  if (row->nb_shots >= MAX_SHOTS) {return;}

  play_sound(SM, &SM->arrow);
  
  row->shots[row->nb_shots++] = get_new_shot(row->rectsize + (gridX-0.5) * row->rectsize,
					     row->rectsize/2 + gridY * row->rectsize,
					     row->rectsize,
					     attack);
}
