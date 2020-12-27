#include "../global_header.h"

enum menu_choices {NONE, NEWGAME, RESUME, SCORE, BACK, SOLO, MULTI, EASY, MEDIUM, HARD, LAUNCH, PAUSE_PLAY, PAUSE_QUIT, PAUSE_SAVE_QUIT,RESTART};
typedef enum menu_choices menu_choice;

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
} Geometry;

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
} Container;

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
  MLV_Color background_color;
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





/* button.c */
void draw_button(Button *this);
bool is_btn_hover(Button *this, int posX, int posY);
bool is_btn_select(Button *this);
Button get_new_button(Geometry g, char *text, MLV_Color color, MLV_Color background_color, char *font_path, menu_choice value);
void set_hover_btn(Button *this);
void unset_hover_btn(Button *this);
void set_select_btn(Button *this);
void unset_select_btn(Button *this);
void set_hidden_btn(Button *this);
void unset_hidden_btn(Button *this);

/* general.c */
void draw_input_or_label(Input *input, Label *label);
char *get_input_or_label_value(Input *input, Label *label);
void set_object_dimension(char *text, char *font_path, int font_size, int *object_width, int *object_height);
int get_object_font_size(char *text, char *font_path, int max_width, int max_height);

/* input.c */
void draw_input(Input *this);
Input get_new_input(Geometry g, char *placeholder, MLV_Color color, char *font_path);
void free_input(Input *this);
void set_hidden_input(Input *this);
void unset_hidden_input(Input *this);
void set_input_geometry(Input *this, int posX, int width);
bool exist_input(Input *this);

/* label.c */
void draw_label(Label *this);
Label get_new_label(Geometry g, char *text, MLV_Color color, char *font_path);
void set_hidden_lbl(Label *this);
void unset_hidden_lbl(Label *this);
void set_label_geometry(Label *this, int posX);
