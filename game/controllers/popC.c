#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void create_new_gold(Game_Manager *GM, Texture_Manager *TM) {
  int random_row, random_column;
  random_row = rand() % NB_ROWS;
  random_column = rand() % NB_COLUMNS;
  if (GM->rows[random_row].nb_golds >= MAX_GOLDS) {return;}

  GM->rows[random_row].golds[GM->rows[random_row].nb_golds++] = get_new_gold(random_column, random_row, &GM->window, TM->gold_img);
  GM->p1.last_free_gold = MLV_get_time();
}

/* GLOBAL */
void check_click_gold(Game_Manager *GM, int mouseX, int mouseY) {
  int i, j;
  Gold *g;
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<GM->rows[i].nb_golds; j++) {
      g = &GM->rows[i].golds[j];
      if (mouseX >= g->centerX - g->radius/2 && mouseX <= g->centerX + g->radius/2 && mouseY >= g->centerY - g->radius/2 && mouseY <=g->centerY + g->radius/2) {
	p1_add_gold(&GM->p1, g->value);
	remove_gold_from_row(&GM->rows[i], j);
	break;
      }
    }
  }
}
