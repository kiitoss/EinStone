#include "../menu_structures.h"
#include "../menu_functions.h"

/* GLOBAL */
void set_player_name(Newgame_Page *this, MLV_Input_box *input_box, char *text_input) {
  char *font_path = "./resources/font/Amatic-Bold.ttf";
  Geometry g;
  g.width = this->width/3;
  if (input_box == this->p1_input.object) {
    g.height = this->p1_input.height;
    g.posX = 0;
    g.posY = this->p1_input.posY;
  
    this->p1_lbl = get_new_label(g, text_input, MLV_COLOR_RED, font_path);
    g.posX = (this->select_gamemode->value == MULTI) ? (this->width/2 - this->p1_lbl.width)/2  : (this->width - this->p1_lbl.width)/2;
    set_label_geometry(&this->p1_lbl, g.posX);
    unset_hidden_lbl(&this->p1_lbl);
    free_input(&this->p1_input);
  }
  else if (input_box == this->p2_input.object) {
    g.height = this->p2_input.height;
    g.posX = this->width/2 + 10;
    g.posY = this->p2_input.posY;
    
    this->p2_lbl = get_new_label(g, text_input, MLV_COLOR_RED, font_path);
    unset_hidden_lbl(&this->p2_lbl);
    free_input(&this->p2_input);
  }
}

/* GLOBAL */
void set_difficulty(Newgame_Page *this, btn_value btn_value) {
  if (this->select_difficulty != NULL && this->select_difficulty->value == btn_value) {return;}

  unset_select_btn(this->select_difficulty);
  
  switch (btn_value) {
  case EASY:
    set_select_btn(&this->easy_btn);
    this->select_difficulty = &this->easy_btn;
    break;
  case MEDIUM:
    set_select_btn(&this->medium_btn);
    this->select_difficulty = &this->medium_btn;
    break;
  case HARD:
    set_select_btn(&this->hard_btn);
    this->select_difficulty = &this->hard_btn;
    break;
  default:
    break;
  }
}

/* GLOBAL */
void set_gamemode(Newgame_Page *this, btn_value btn_value) {
  if (this->select_gamemode != NULL && this->select_gamemode->value == btn_value) {return;}

  unset_select_btn(this->select_gamemode);
  
  switch (btn_value) {
  case SOLO:
    set_select_btn(&this->solo_btn);
    this->select_gamemode = &this->solo_btn;
    unset_hidden_btn(&this->easy_btn);
    unset_hidden_btn(&this->medium_btn);
    unset_hidden_btn(&this->hard_btn);

    if (exist_input(&this->p2_input)) {
      set_hidden_input(&this->p2_input);
    }
    else {
      set_hidden_lbl(&this->p2_lbl);
    }

    if (exist_input(&this->p1_input)) {
      set_input_geometry(&this->p1_input, 3*this->width/8, this->width/4);
    }
    else {
      set_label_geometry(&this->p1_lbl, (this->width-this->p1_lbl.width)/2);
    }

    if (exist_input(&this->p1_input)) {
      MLV_activate_input_box(this->p1_input.object);
    }
    break;

    
  case MULTI:
    set_select_btn(&this->multi_btn);
    this->select_gamemode = &this->multi_btn;
    set_hidden_btn(&this->easy_btn);
    set_hidden_btn(&this->medium_btn);
    set_hidden_btn(&this->hard_btn);

    if (exist_input(&this->p2_input)) {
      unset_hidden_input(&this->p2_input);
    }
    else {
      unset_hidden_lbl(&this->p2_lbl);
    }

    if (exist_input(&this->p1_input)) {
      set_input_geometry(&this->p1_input, this->width/4 - 10, this->width/4);
    }
    else {
      set_label_geometry(&this->p1_lbl, (this->width/2-this->p1_lbl.width)/2 - 10);
    }

     if (exist_input(&this->p2_input)) {
       MLV_activate_input_box(this->p2_input.object);
     }
     else if (exist_input(&this->p1_input)) {
       MLV_activate_input_box(this->p1_input.object);
     }
    break;
  default:
    break;
  }
}

/* GLOBAL */
Newgame_Page init_newgame_page(int width, int height) {
  Newgame_Page ngp;
  Geometry g;
  int margin_title = height/3 * 0.2;
  int title_height = height/3 * 0.8;
  
  int margin_row = 2*height/3 * 0.3/4;
  int row_height = 2*height/3 * 0.7/4;
  char *font_path = "./resources/font/Amatic-Bold.ttf";

  ngp.hover_btn = NULL;
  ngp.select_gamemode = NULL;
  ngp.select_difficulty = NULL;
  
  g.width = width;
  g.height = title_height;
  g.posX = 0;
  g.posY = 0;

  ngp.width = width;
  ngp.height = height;
  
  ngp.title_lbl = get_new_label(g, "Ein Stone", MLV_COLOR_RED, font_path);

  g.height = row_height;
  g.posY += title_height + margin_title;
  g.width = width/4;
  g.posX = width/4;
  ngp.solo_btn = get_new_button(g, "SOLO", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, SOLO);
  g.posX += width/4;
  ngp.multi_btn = get_new_button(g, "MULTI", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, MULTI);

  g.posY += row_height + margin_row;
  g.width = width/4;
  g.posX = width/4 - 10;
  ngp.p1_input = get_new_input(g, "Joueur 1: ", MLV_COLOR_RED, font_path);
  g.posX = width/2 + 10;
  ngp.p2_input = get_new_input(g, "Joueur 2: ", MLV_COLOR_RED, font_path);
  
  g.posY += row_height + margin_row;
  g.width = width/3;
  g.posX = 0;
  ngp.easy_btn = get_new_button(g, "EASY", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, EASY);
  g.posX += width/3;
  ngp.medium_btn = get_new_button(g, "MEDIUM", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, MEDIUM);
  g.posX += width/3;
  ngp.hard_btn = get_new_button(g, "HARD", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, HARD);
  

  g.posY += row_height + margin_row;
  g.width = width/4;
  g.posX = 0;
  ngp.back_btn = get_new_button(g, "Back", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, BACK);
  g.posX = 3*width/4;
  ngp.launch_btn = get_new_button(g, "Launch", MLV_COLOR_RED, MLV_rgba(0,0,0,0), font_path, LAUNCH);

  return ngp;
}


/* GLOBAL */
Button *get_newgame_page_hover_btn(Newgame_Page *this, int posX, int posY) {
  Button *hover_btn = NULL;
  if (is_btn_hover(&this->solo_btn, posX, posY)) {
    hover_btn = &this->solo_btn;
  }
  else if (is_btn_hover(&this->multi_btn, posX, posY)) {
    hover_btn = &this->multi_btn;
  }
  else if (is_btn_hover(&this->easy_btn, posX, posY)) {
    hover_btn = &this->easy_btn;
  }
  else if (is_btn_hover(&this->medium_btn, posX, posY)) {
    hover_btn = &this->medium_btn;
  }
  else if (is_btn_hover(&this->hard_btn, posX, posY)) {
    hover_btn = &this->hard_btn;
  }
  else if (is_btn_hover(&this->back_btn, posX, posY)) {
    hover_btn = &this->back_btn;
  }
  else if (is_btn_hover(&this->launch_btn, posX, posY)) {
    hover_btn = &this->launch_btn;
  }
  return hover_btn;
}
