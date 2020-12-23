#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

/* Reproduction de la variable booléen */
enum bool {false, true};
typedef enum bool bool;

enum menu_choices {NONE, NEWGAME, RESUME, SCORE, BACK, SOLO, MULTI, EASY, MEDIUM, HARD, LAUNCH};
typedef enum menu_choices menu_choice;

typedef struct {
  MLV_Event event;
  int mouseX;
  int mouseY;
  MLV_Button_state btn_state;
  MLV_Keyboard_button touch;
  char *text_input;
  MLV_Input_box *input_box;
} Event_Manager;

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
} Geometry;

typedef struct {
  MLV_Sound *sound;
  float sound_level;
} Sound;

typedef struct {
  bool sound_works;
  Sound arrow;
  Sound big_monster_roar;
  Sound gold;
  Sound punch;
  Sound spear;
} Sound_Manager;
