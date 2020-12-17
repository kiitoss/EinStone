/* #include "../global.h" */
#include <MLV/MLV_all.h>
#define MAX_BUTTONS 10
#define MAX_INPUTS 10
#define MAX_LABELS 10
#define MAX_SECTIONS 10

enum bool {false, true};
typedef enum bool bool;
enum menu_choices {NONE, NEWGAME, RESUME, SCORE, BACK, SOLO, DUO, EASY, MEDIUM, HARD, LAUNCH};
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
  int width;
  int height;
  int posX;
  int posY;
  int last_posX;
  int last_posY;
  char *text;
  char *font_path;
  int font_size;
  MLV_Color color;
  bool is_hidden;
} Label;

typedef struct {
  Geometry container;
  int width;
  int height;
  int posX;
  int posY;
  char *text;
  char *font_path;
  int font_size;
  MLV_Color color;
  bool is_hover;
  bool is_select;
  menu_choice value;
  bool is_hidden;
} Button;

typedef struct {
  int width;
  int height;
  int posX;
  int posY;
  char *placeholder;
  char *font_path;
  int font_size;
  MLV_Color color;
  MLV_Input_box *object;
  bool is_hidden;
  MLV_Font *font;
  Label *label;
} Input;

typedef struct {
  int width;
  int height;
  int posX;
  int posY;
  bool is_hover;
  bool is_select;
} Section;

typedef struct {
  int width;
  int height;
  Label title;
  Label labels[MAX_LABELS];
  int nb_labels;
  Input inputs[MAX_INPUTS];
  int nb_inputs;
  Button buttons[MAX_BUTTONS];
  int nb_buttons;
  Section sections[MAX_SECTIONS];
  int nb_sections;
  Button *hover_button;
  Section *hover_section;
  Section *select_section;
} Page;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Button newgame_btn;
  Button resume_btn;
  Button score_btn;
  Button quit_btn;
  Button *hover_btn;
} mainPage;
