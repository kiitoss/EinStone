#include "../../mainHeader.h"
#include "../makhead.h"

/* GLOBAL */
void create_new_gold(Row *row, int gridX, int gridY, Sound_Manager *SM) {
  if (row->nb_golds >= MAX_GOLDS) {return;}

  play_sound(SM, &SM->gold);
  
  row->golds[row->nb_golds++] = get_new_gold((rand() % row->rectsize) + gridX * row->rectsize,
					     (rand() % row->rectsize) + gridY * row->rectsize,
					     row->rectsize);
}

/* GLOBAL */
void check_click_gold(Game_Manager *GM, int mouseX, int mouseY) {
  int i, j;
  Gold *g;
  bool get = false;
  mouseX -= GM->window.field.posX;
  mouseY -= GM->window.field.posY;
  
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<GM->rows[i].nb_golds; j++) {
      g = &GM->rows[i].golds[j];
      if (mouseX >= g->centerX - g->radius/2 && mouseX <= g->centerX + g->radius/2 && mouseY >= g->centerY - g->radius/2 && mouseY <=g->centerY + g->radius/2) {
	p1_add_gold(&GM->p1, g->value);
	remove_gold_from_row(&GM->rows[i], j);
	get = true;
	break;
      }
    }
    if (get) {break;}
  }
}

/* GLOBAL */
void create_new_shot(Row *row, int gridX, int gridY, int attack, Sound_Manager *SM) {
  if (row->nb_shots >= MAX_SHOTS) {return;}

  play_sound(SM, &SM->arrow);
  
  row->shots[row->nb_shots++] = get_new_shot(row->rectsize + (gridX-0.5) * row->rectsize,
					     row->rectsize/2 + gridY * row->rectsize,
					     row->rectsize,
					     attack);
}
