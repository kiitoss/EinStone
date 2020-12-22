/*
------------------------------------------------------------

MAKMAK from path: ./

------------------------------------------------------------
*/
/* models/animationM.c */
MLV_Animation *get_animation(MLV_Image *sprite, int rectsize, int row_animation, int first_frame, int last_frame, int time);

/* models/gameManagerM.c */
Game_Manager init_GM(Window *window, Texture_Manager *TM);

/* models/spawnersM.c */
Friend_Spawner init_FS(int index_friend, Texture_Manager *TM, Window *window);
Enemy_Spawner init_ES(int index_enemy, Texture_Manager *TM, Window *window);

/* models/textureManagerM.c */
Texture_Manager init_TM(Window window);

/* models/windowM.c */
Window init_window(unsigned int win_width, unsigned int win_height, menu_choice gamemode);

/* views/gameV.c */
void draw_game(Game_Manager *GM, Texture_Manager *TM);
Event_Manager get_game_event();

/* views/windowV.c */
void draw_window(Game_Manager *GM, Texture_Manager *TM);

