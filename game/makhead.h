/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* controllers/enemyC.c */
void update_enemy_animation(Enemy *this, Row *row);

/* controllers/friendC.c */
void update_friend_animation(Friend *this, Row *row);

/* controllers/playerC.c */
void p1_buy_friend(Player_1 *this, Row *row, Friend_Spawner *spawner, int gridX, int gridY);
void p2_buy_enemy(Player_2 *this, Row *row, Enemy_Spawner *spawner, int posX, int posY);

/* controllers/popC.c */
void create_new_gold(Game_Manager *GM, Texture_Manager *TM);
void check_click_gold(Game_Manager *GM, int mouseX, int mouseY);

/* controllers/rowC.c */
void remove_gold_from_row(Row *this, int index_gold);
void add_friend_in_row(Row *this, Friend_Spawner *spawner, int gridX, int gridY);
void add_enemy_in_row(Row *this, Enemy_Spawner *spawner, int posX, int posY);
void update_gold(Gold *this);
void update_rows(Game_Manager *GM, Texture_Manager *TM);

/* models/animationM.c */
MLV_Animation *get_animation(MLV_Image *sprite, int rectsize, int row_animation, int first_frame, int last_frame, int time);

/* models/enemyM.c */
void move_enemy(Enemy *this);
void set_enemy_animation(Enemy *this, MLV_Animation_player *animation);
Enemy get_new_enemy(Enemy_Spawner *spawner, int posX, int posY);

/* models/friendM.c */
bool is_friend(Friend *this);
void set_friend_animation(Friend *this, MLV_Animation_player *animation);
Friend get_new_friend(Friend_Spawner *spawner, int posX, int posY);

/* models/gameManagerM.c */
Game_Manager init_GM(Window *window, Texture_Manager *TM, menu_choice gamemode);

/* models/goldM.c */
Gold get_new_gold(int gridX, int gridY, Window *window, MLV_Image *img);

/* models/playerM.c */
void set_player_money_str(int money, char money_str[10]);
void p1_add_gold(Player_1 *this, int gold);
Player_1 init_p1();
Player_2 init_p2();

/* models/rowM.c */
Row init_row(int rectsize);

/* models/spawnerM.c */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window);
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window);

/* models/textureManagerM.c */
void set_img_size(MLV_Image *img, int width, int height);
Texture_Manager init_TM(Window window);

/* models/windowM.c */
Window init_window(unsigned int win_width, unsigned int win_height, menu_choice gamemode);

/* views/gameV.c */
void draw_game(Game_Manager *GM, Texture_Manager *TM);
Event_Manager get_game_event();

/* views/windowV.c */
void draw_window(Game_Manager *GM, Texture_Manager *TM);

