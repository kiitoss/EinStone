#include "../menuHeader.h"
#include "../makhead.h"

/* GLOBAL */
void draw_button(Button *this) {
  MLV_Font* font;
  MLV_Color background_color;
  int border_size = 5;
  
  if (this->is_hidden) {return;}
  
  font = MLV_load_font(this->font_path , this->font_size);

  if (this->is_select || this->is_hover) {
    if (this->is_select) {
      background_color = MLV_COLOR_GREEN;
    }
    else {
      background_color = MLV_COLOR_ORANGE;
    }

    MLV_draw_rectangle(this->container.posX, this->container.posY - border_size, this->container.width, this->container.height + 2*border_size, background_color);
    MLV_draw_filled_rectangle(this->container.posX, this->container.posY, this->container.width, this->container.height, background_color);
  }

  MLV_draw_adapted_text_box_with_font(this->posX, this->posY, this->text, font, 0, MLV_rgba(0,0,0,0), this->color, MLV_rgba(0,0,0,0), MLV_TEXT_CENTER);
  MLV_free_font(font);
}

/* GLOBAL */
void draw_label(Label *this) {
  MLV_Font* font;

  if (this->is_hidden) {return;}

  font = MLV_load_font(this->font_path , this->font_size);
  MLV_draw_adapted_text_box_with_font(this->posX, this->posY, this->text, font, 0, MLV_rgba(0,0,0,0), this->color, MLV_rgba(0,0,0,0), MLV_TEXT_CENTER);
  MLV_free_font(font);
}

/* GLOBAL */
void draw_input(Input *this) {
  if (this->is_hidden) {return;}
  MLV_draw_input_box(this->object);
}


/* GLOBAL */
void draw_input_or_label(Input *input, Label *label) {
  if (exist_input(input)) {
    draw_input(input);
  }
  else {
    draw_label(label);
  }
}


/* GLOBAL */
void draw_resume_section(resumeSection *this) {
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
  draw_label(&this->section_lbl);
}
