#define NB_FRIENDS 4
#define NB_ENEMIES 3
#define NB_ROWS 5
#define NB_COLUMNS 8
/* MAX_ENEMIES est le nombre maximum d'ennemis par ligne */
#define MAX_ENEMIES 100
/* MAX_SHOTS est le nombre maximum de flèches par ligne */
#define MAX_SHOTS 100
/* MAX_GOLDS est le nombre maximum de pièces d'or par ligne */
#define MAX_GOLDS 50
/* MAX_FRAMES est le maximum de frames par animation */
#define MAX_FRAMES 15
#define DELAY_REFRESH 50
#define DELAY_FREE_GOLD_P1 5000
#define DELAY_FREE_GOLD_P2 2500
#define QTY_FREE_GOLD_P2 100
#define EXPO_GOLD_IA 5
#define AMOUNT_GOLD_P1 100
#define LIFE_P1 3
#define INIT_GOLD_P1 100
#define INIT_GOLD_P2 100

#define SAVED_GAMES 5
#define SAVED_SCORES 10
#define FULL_SCREEN true

enum friend_abilities {ATTACK, DEFENSE, MONEY};
enum enemy_type_attacks {CAC, DISTANCE};
typedef enum enemy_type_attacks enemy_type_attacks;
typedef enum friend_abilities friend_abilities;

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
  MLV_Sound *sound;
  float sound_level;
} Sound;

typedef struct {
  MLV_Music *music;
  float music_level;
} Music;

typedef struct {
  bool sound_works;
  Sound arrow;
  Sound big_monster_roar;
  Sound gold;
  Sound punch;
  Sound spear;
  Music game;
  Music menu;
  bool menu_music_playing;
} Sound_Manager;

typedef struct {
  int width;
  int height;
  int rectsize;
  Container field;
  Container friend_spawner;
  Container enemy_spawner;
  Container friend_home;
  Container enemy_home;
  Label time_lbl;
} Window;

typedef struct {
  int centerX;
  int centerY;
  int time_left;
  int radius;
  int max_radius;
} Gold;

typedef struct {
  int posX;
  int posY;
  int attack;
  int speed;
} Shot;

typedef struct {
  char name[21];
  int chosen_friend;
  long money;
  char money_str[10];
  int last_free_gold;
  int score;
  int life;
  bool is_deleting;
} Player_1;

typedef struct {
  char name[21];
  int chosen_enemy;
  int chosen_row;
  long money;
  char money_str[10];
  int last_free_gold;
} Player_2;

typedef struct {
  int id_friend;
  MLV_Animation *animation_passive;
  MLV_Animation *animation_ability;
  friend_abilities ability;
  int life;
  int attack;
  int price;
  char price_str[5];
  int DELAY_ABILITY;
  int range;
} Friend_Spawner;

typedef struct {
  int id_enemy;
  MLV_Animation *animation_attack;
  MLV_Animation *animation_walking;
  enemy_type_attacks type_attack;
  int life;
  int score;
  int attack;
  int speed;
  int price;
  char price_str[5];
  int DELAY_ATTACK;
  int range;
  int padding;
} Enemy_Spawner;

typedef struct {
  int id_friend;
  MLV_Animation_player *animation_passive;
  MLV_Animation_player *animation_ability;
  MLV_Animation_player *animation;
  friend_abilities ability;
  int life;
  int attack;
  int delay_ability;
  int DELAY_ABILITY;
  int range;
  int posX;
  int posY;
  bool is_passive;
} Friend;

typedef struct {
  int id_enemy;
  MLV_Animation_player *animation_attack;
  MLV_Animation_player *animation_walking;
  MLV_Animation_player *animation;
  enemy_type_attacks type_attack;
  int life;
  int attack;
  int speed;
  int DELAY_ATTACK;
  int delay_attack;
  int range;
  int posX;
  int posY;
  int score;
  bool is_walking;
  int padding;
} Enemy;

typedef struct {
  Friend friends[NB_COLUMNS];
  Enemy enemies[MAX_ENEMIES];
  int nb_enemies;
  Shot shots[MAX_SHOTS];
  int nb_shots;
  Gold golds[MAX_GOLDS];
  int nb_golds;
  int rectsize;
} Row;

typedef struct {
  int id;
  bool in_game;
  btn_value gamemode;
  btn_value difficulty;
  Window window;
  Friend_Spawner friend_spawners[NB_FRIENDS];
  Enemy_Spawner enemy_spawners[NB_ENEMIES];
  Row rows[NB_ROWS];
  Player_1 p1;
  Player_2 p2;
  int last_refresh;
  long duration;
  MLV_Button_state last_state_mouse;
  MLV_Button_state last_state_key;
} Game_Manager;

typedef Game_Manager GM_list_games[SAVED_GAMES];
typedef Game_Manager GM_list_scores[SAVED_SCORES];

typedef struct {
  Button play_btn;
  Button save_quit_btn;
  Button quit_btn;
  Button *hover_btn;
} Pause_Screen;

typedef struct {
  Button quit_btn;
  Button restart_btn;
  Button *hover_btn;
} Game_Over;

typedef struct {
  MLV_Image *field_light_grass_img;
  MLV_Image *field_dark_grass_img;
  MLV_Image *enemy_spawner_background;
  MLV_Image *friend_spawner_background;
  MLV_Image *friend_home_background;
  MLV_Image *enemy_home_background;
  MLV_Image *friend_spawners_sprites[NB_FRIENDS];
  MLV_Image *enemy_spawners_sprites[NB_ENEMIES];
  MLV_Image *friend_spawners_imgs[NB_FRIENDS];
  MLV_Image *enemy_spawners_imgs[NB_ENEMIES];
  MLV_Image *gold_img;
  MLV_Image *shot_img;
  MLV_Image *life_friend_img;
  MLV_Image *delete_friend_img;
  MLV_Image *score_img;
  MLV_Font *font;
  int font_size;
  Pause_Screen pause_screen;
  Game_Over game_over_screen;
} Texture_Manager;
