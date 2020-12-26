/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/


void draw_game_over_screen(gameOver *this,Game_Manager *GM);
/* controllers/IA.c */
void update_IA(Game_Manager *GM);

/* controllers/enemy.c */
Enemy get_new_enemy(Enemy_Spawner *spawner, int posX, int posY);
void set_enemy_animation(Enemy *this, MLV_Animation_player *animation);
void update_enemy(Enemy *this, Row *row, Sound_Manager *SM);

/* controllers/friend.c */
Friend get_new_friend(Friend_Spawner *spawner, int posX, int posY);
bool is_friend(Friend *this);
void set_friend_animation(Friend *this, MLV_Animation_player *animation);
void update_friend(Friend *this, Row *row, Sound_Manager *SM);

/* controllers/player.c */
void set_player_money_str(int money, char money_str[10]);
void set_player_life_str(int life, char life_str[10]);
void p1_add_gold(Player_1 *this, int gold);
Player_1 init_p1(char *p1_name);
Player_2 init_p2(char *p2_name);
void p2_create_free_gold(Player_2 *this);
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY);
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY);

/* controllers/pop.c */
Shot get_new_shot(int posX, int posY, int rectsize, int attack);
bool is_clicked_gold(Gold *this, int mouseX, int mouseY);
Gold get_new_gold(int centerX, int centerY, int rectsize);
void update_gold(Gold *this);
void move_shot(Shot *this);
void create_new_gold(Row *row, int gridX, int gridY, Sound_Manager *SM);
void create_new_shot(Row *row, int gridX, int gridY, int attack, Sound_Manager *SM);

/* controllers/row.c */
void remove_friend_from_row(Friend *f);
void remove_gold_from_row(Row *this, int index_gold);
void remove_shot_from_row(Row *this, int index_shot);
void remove_enemy_from_row(Row *this, int index_enemy, Sound_Manager *SM);
void add_friend_in_row(Row *this, Friend_Spawner *spawner, int gridX, int gridY);
void add_enemy_in_row(Row *this, Enemy_Spawner *spawner, int posX, int posY);
void update_row(Row *this, Game_Manager *GM, Sound_Manager *SM);

/* initializers/init_IA.c */
void init_IA(Game_Manager *GM);

/* initializers/init_gameManager.c */
Game_Manager init_GM(Window *window, Texture_Manager *TM, menu_choice gamemode,menu_choice difficulty,char *p1_name,char *p2_name);

/* initializers/init_row.c */
Row init_row(int rectsize);

/* initializers/init_soundManager.c */
void play_sound(Sound_Manager *SM, Sound *this);
Sound_Manager init_game_SM();
void free_SM(Sound_Manager *SM);

/* initializers/init_spawner.c */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window);
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window);

/* initializers/init_textureManager.c */
void set_img_size(MLV_Image *img, int width, int height);
Texture_Manager init_TM(Window window);
void free_TM(Texture_Manager *this);

/* initializers/init_window.c */
Window init_window(unsigned int win_width, unsigned int win_height, menu_choice gamemode);

/* views/game_view.c */
void draw_game(Game_Manager *GM, Texture_Manager *TM, int time);
Event_Manager get_game_event();

/* views/window_view.c */
void draw_time(int time, Window *window);
void draw_pause_screen(pauseScreen *this);
void draw_window(Game_Manager *GM, Texture_Manager *TM);

/* game.c */
void quit_game(Game_Manager *GM, Texture_Manager *TM, Sound_Manager *SM);

