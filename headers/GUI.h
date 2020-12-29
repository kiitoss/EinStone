enum btn_values {NONE, NEWGAME, RESUME, SCORE, BACK, SOLO, MULTI, EASY, MEDIUM, HARD, LAUNCH, PAUSE_PLAY, PAUSE_QUIT, PAUSE_SAVE_QUIT,RESTART};
typedef enum btn_values btn_value;

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
  btn_value value;
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
