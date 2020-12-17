#include "../../menuHeader.h"
#include "../../makhead.h"

/* GLOBAL */
Button *get_main_page_hover_btn(mainPage *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->newgame_btn, posX, posY)) {
    printf("A\n");
    hover_btn = &this->newgame_btn;
  }
  else if (is_btn_hover(&this->resume_btn, posX, posY)) {
    printf("B\n");
    hover_btn = &this->resume_btn;
  }
  else if (is_btn_hover(&this->score_btn, posX, posY)) {
    printf("C\n");
    hover_btn = &this->score_btn;
  }
  else if (is_btn_hover(&this->quit_btn, posX, posY)) {
    printf("D\n");
    hover_btn = &this->quit_btn;
  }
  return hover_btn;
}
