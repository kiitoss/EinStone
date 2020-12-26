#include "../../mainHeader.h"
#include "../makhead.h"





/* Retourne une ligne initialisée. */
/* GLOBAL */
Row init_row(int rectsize) {
  Row r;
  int i;
  for (i=0; i<NB_COLUMNS; i++) {
    r.friends[i].id_friend = -1;
  }
  r.nb_enemies = 0;
  r.nb_shots = 0;
  r.nb_golds = 0;
  r.rectsize = rectsize;
  return r;
}
