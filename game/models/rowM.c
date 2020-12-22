#include "../gameHeader.h"
#include "../makhead.h"

/* GLOBAL */
Row init_row() {
  Row r;
  int i;
  for (i=0; i<NB_COLUMNS; i++) {
    r[i].id_friend = 0;
  }
  return r;
}
