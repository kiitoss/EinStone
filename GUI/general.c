#include "GUI_header.h"

typedef struct _MLV_List MLV_List;

struct _MLV_List {
	MLV_List* previous;
	MLV_List* next;
	void* data;
};

struct _MLV_Input_box {
    int sommetHautGauche[2];
    int sommetBasDroit[2];
    int width;
    int height;
    SDL_Rect rectangle;
	const MLV_Font* font;
    int bord[2];
    int widthMessage;
    int widthAnswer;
	int heightMessAns;
    MLV_Color borderColor;
    MLV_Color textColor;
    MLV_Color backgroundColor;
    SDL_Surface* apparence;
    SDL_Surface* answer;
    SDL_Rect answerRectangle;
    char* informativeMessage;
    int positionCursor;
    int lastTime;
    int cursorIsVisible;
    int isListenning;
    MLV_List* history;
    MLV_List* positionHistory;
    SDL_sem* semaphore;
};



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
char *get_input_or_label_value(Input *input, Label *label) {
  char *value;
  if (exist_input(input)) {
    value = input->object->history->data;
  }
  else {
    value = label->text;
  }
  return value;
}


/* GLOBAL */
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height) {
  MLV_Font *font = MLV_load_font(font_path, font_size);
  MLV_get_size_of_adapted_text_box_with_font(text, font, 0, object_width, object_height);
  MLV_free_font(font);
}

/* GLOBAL */
int get_object_font_size(char *text, char *font_path, int max_width, int max_height){
  MLV_Font *font;
  int font_size = 1;
  int width = 0;
  int height = 0;
  while (width <= max_width && height <= max_height) {
    font = MLV_load_font(font_path, font_size);
    MLV_get_size_of_adapted_text_box_with_font(text, font, 0, &width, &height);
    MLV_free_font(font);
    font_size++;
  }
  return font_size;
}
