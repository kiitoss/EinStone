#include "../../menuHeader.h"
#include "../../makhead.h"

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
