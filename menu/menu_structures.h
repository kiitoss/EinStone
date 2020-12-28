#include "../global_structures.h"
#include "../global_functions.h"

#define MAX_BUTTONS 10
#define MAX_INPUTS 10
#define MAX_LABELS 10
#define MAX_SECTIONS 10

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Button newgame_btn;
  Button resume_btn;
  Button score_btn;
  Button quit_btn;
  Button *hover_btn;
} Main_Page;

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
} Newgame_Page;


typedef struct {
  Game_Manager *GM;
  bool exist;
  int width;
  int height;
  int posX;
  int posY;
  Label p1_name_lbl;
  Label p2_name_lbl;
  Label p1_score_lbl;
  Label p2_score_lbl;
  Label time_lbl;
  bool is_hover;
  bool is_select;
} Resume_Section;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Resume_Section sections[SAVED_GAMES];
  Button launch_btn;
  Button back_btn;
  Button *hover_btn;
  Resume_Section *select_section;
  Resume_Section *hover_section;
} Resume_Page;

typedef struct {
  bool exist;
  int width;
  int height;
  int posX;
  int posY;
  Label p1_name_lbl;
  Label p1_score_lbl;
  Label time_lbl;
} Score_Section;

typedef struct {
  int width;
  int height;
  Label title_lbl;
  Score_Section sections[SAVED_SCORES];
  Button back_btn;
  Button *hover_btn;
} Score_Page;
