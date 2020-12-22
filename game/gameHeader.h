#include "../mainHeader.h"

#define NB_FRIENDS 3
#define NB_ENEMIES 1
#define NB_ROWS 5
#define NB_COLUMNS 8
/* MAX_ENEMIES est le nombre maximum d'ennemis par ligne */
#define MAX_ENEMIES 100
/* MAX_SHOTS est le nombre maximum de flèches par ligne */
#define MAX_SHOTS 100
/* MAX_GOLDS est le nombre maximum de pièces d'or par ligne */
#define MAX_GOLDS 100
/* MAX_FRAMES est le maximum de frames par animation */
#define MAX_FRAMES 15
#define DELAY_REFRESH 100

enum friend_abilities {ATTACK, DEFENSE, MONEY};
typedef enum friend_abilities friend_abilities;

typedef struct {
  int posX;
  int posY;
  int width;
  int height;
} Container;

typedef struct {
  int width;
  int height;
  int rectsize;
  Container field;
  Container friend_spawner;
  Container enemy_spawner;
  Container friend_home;
  Container enemy_home;
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
  int width;
  int attack;
  int speed;
} Shot;

typedef struct {
  char *name;
  int chosen_friend;
  int money;
  char *money_str;
  int last_free_gold;
  int delay_free_gold;
  int score;
} Player_1;

typedef struct {
  char *name;
  int chosen_enemy;
  int chosen_row;
  int money;
  char *money_str;
  int last_free_gold;
  int delay_free_gold;
  int score;
} Player_2;

typedef struct {
  int id_friend;
  MLV_Animation *animation_passive;
  MLV_Animation *animation_ability;
  friend_abilities ability;
  int delay_frame_ability;
  int life;
  int attack;
  int price;
  char price_str[5];
  int delay_ability;
  int range;
} Friend_Spawner;

typedef struct {
  MLV_Animation *animation_attack;
  MLV_Animation *animation_walking;
  int life;
  int attack;
  int speed;
  int price;
  char price_str[5];
  int delay_frame_attack;
  int delay_attack;
  int range;
} Enemy_Spawner;

typedef struct {
  int id_friend;
  MLV_Animation_player *animation_passive;
  MLV_Animation_player *animation_ability;
  friend_abilities ability;
  int delay_frame_ability;
  int life;
  int attack;
  int delay_ability;
  int range;
  int posX;
  int posY;
  bool is_passive;
} Friend;

typedef struct {
  MLV_Animation *animation_attack;
  MLV_Animation *animation_walking;
  int life;
  int attack;
  int speed;
  int delay_frame_attack;
  int delay_attack;
  int range;
  int posX;
  int posY;
  bool is_walking;
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
  menu_choice gamemode;
  menu_choice difficulty;
  Window window;
  Friend_Spawner friend_spawners[NB_FRIENDS];
  Enemy_Spawner enemy_spawners[NB_ENEMIES];
  Row rows[NB_ROWS];
  Player_1 p1;
  Player_2 p2;
  int last_refresh;
} Game_Manager;

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
} Texture_Manager;
