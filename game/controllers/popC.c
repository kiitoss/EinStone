#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
void create_new_gold(Row *row, int gridX) {
  if (row->nb_golds >= MAX_GOLDS) {return;}

  row->golds[row->nb_golds++] = get_new_gold((rand() % row->rectsize) + gridX * row->rectsize + row->posX,
					     (rand() % row->rectsize) + row->posY,
					     row->rectsize);
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

/* GLOBAL */
void create_new_shot(Row *row, int gridX, int attack) {
  if (row->nb_shots >= MAX_SHOTS) {return;}

  row->shots[row->nb_shots++] = get_new_shot(row->rectsize + (gridX-0.5) * row->rectsize + row->posX,
					     row->posY + row->rectsize/2,
					     row->rectsize,
					     attack);
}
