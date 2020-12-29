#include "../../headers/global_header.h"


/* GLOBAL */
Event_Manager get_event() {
  Event_Manager em;
  em.event = MLV_get_event(&em.touch, NULL, NULL, &em.text_input, &em.input_box, &em.mouseX, &em.mouseY, NULL, &em.btn_state);
  return em;
}

/* GLOBAL */
void draw_main_page(Main_Page *mp) {
  MLV_clear_window(MLV_COLOR_BLACK);
  draw_label(&mp->title_lbl);
  draw_button(&mp->newgame_btn);
  draw_button(&mp->resume_btn);
  draw_button(&mp->score_btn);
  draw_button(&mp->quit_btn);
  MLV_update_window();
}

/* GLOBAL */
void draw_newgame_page(Newgame_Page *ngp) {
  MLV_clear_window(MLV_COLOR_BLACK);

  draw_label(&ngp->title_lbl);
  draw_button(&ngp->solo_btn);
  draw_button(&ngp->multi_btn);
  draw_button(&ngp->easy_btn);
  draw_button(&ngp->medium_btn);
  draw_button(&ngp->hard_btn);
  draw_button(&ngp->back_btn);
  draw_button(&ngp->launch_btn);

  draw_input_or_label(&ngp->p1_input, &ngp->p1_lbl);
  draw_input_or_label(&ngp->p2_input, &ngp->p2_lbl);
  
  MLV_update_window();
}


/* GLOBAL */
void draw_resume_section(Resume_Section *this) {
  MLV_Color border_color = MLV_rgba(0,0,0,0);
  if (!this->exist) {return;}
  if (this->is_select || this->is_hover) {
    if (this->is_select) {
      border_color = MLV_COLOR_GREEN;
    }
    else {
      border_color = MLV_COLOR_ORANGE;
    }
  }
  MLV_draw_rectangle(this->posX, this->posY, this->width, this->height, border_color);
  draw_label(&this->p1_name_lbl);
  draw_label(&this->p1_score_lbl);
  draw_label(&this->time_lbl);
  draw_label(&this->p2_score_lbl);
  draw_label(&this->p2_name_lbl);
}

/* GLOBAL */
void draw_resume_page(Resume_Page *rp) {
  int i;
  MLV_clear_window(MLV_COLOR_BLACK);

  draw_label(&rp->title_lbl);
  draw_button(&rp->back_btn);
  draw_button(&rp->launch_btn);

  for (i=0; i<SAVED_GAMES; i++) {
    draw_resume_section(&rp->sections[i]);
  }
  
  MLV_update_window();
}

/* GLOBAL */
void draw_score_section(Score_Section *this) {
  if (!this->exist) {return;}

  MLV_draw_rectangle(this->posX, this->posY, this->width, this->height, MLV_rgba(0,0,0,0));
  draw_label(&this->p1_name_lbl);
  draw_label(&this->p1_score_lbl);
  draw_label(&this->time_lbl);
}

/* GLOBAL */
void draw_score_page(Score_Page *sp) {
  int i;
  MLV_clear_window(MLV_COLOR_BLACK);

  draw_label(&sp->title_lbl);
  draw_button(&sp->back_btn);

  for (i=0; i<SAVED_SCORES; i++) {
    draw_score_section(&sp->sections[i]);
  }
  
  MLV_update_window();
}
