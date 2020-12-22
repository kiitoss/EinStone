/* #include "../global.h" */
#include <MLV/MLV_all.h>
#define MAX_BUTTONS 10
#define MAX_INPUTS 10
#define MAX_LABELS 10
#define MAX_SECTIONS 10

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
  int width;
  int height;
  int posX;
  int posY;
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
  MLV_Font *font;
  bool is_hidden;
} Input;

/*
typedef struct {
  int width;
  int height;
  int posX;
  int posY;
  bool is_hover;
  bool is_select;
} Section;
*/

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

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Button solo_btn;
  Button multi_btn;
  Button easy_btn;
  Button medium_btn;
  Button hard_btn;
  Button launch_btn;
  Button back_btn;
  Input p1_input;
  Input p2_input;
  Label p1_lbl;
  Label p2_lbl;
  Button *hover_btn;
  Button *select_gamemode;
  Button *select_difficulty;
} newgamePage;


typedef struct {
  int width;
  int height;
  int posX;
  int posY;
  Label section_lbl;
  bool is_hover;
  bool is_select;
} resumeSection;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  resumeSection sections[5];
  Button launch_btn;
  Button back_btn;
  Button *hover_btn;
  resumeSection *select_section;
  resumeSection *hover_section;
} resumePage;
