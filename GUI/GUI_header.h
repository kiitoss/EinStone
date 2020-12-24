#include "../global_header.h"

enum menu_choices {NONE, NEWGAME, RESUME, SCORE, BACK, SOLO, MULTI, EASY, MEDIUM, HARD, LAUNCH};
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

typedef struct {
  bool exist;
  int width;
  int height;
  int posX;
  int posY;
  Label section_lbl;
  bool is_hover;
  bool is_select;
} resumeSection;
