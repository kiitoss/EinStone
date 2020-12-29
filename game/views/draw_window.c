#include "../../headers/global_header.h"



/* Dessine le temps actuel du jeu. */
void draw_time(int time, Window *window) {
  int min = (time / 1000) / 60;
  int sec = (time / 1000) - min*60;
  char msg[20];
  sprintf(msg, "%dm : %ds", min, sec);
  window->time_lbl.text = msg;
  draw_label(&window->time_lbl);
}



/* Dessin l'ecran de pause. */
void draw_pause_screen(Pause_Screen *this) {
  draw_button(&this->play_btn);
  draw_button(&this->save_quit_btn);
  draw_button(&this->quit_btn);

  MLV_update_window();
}



/* Dessine l'ecran de Game Over. */
void draw_game_over_screen(Game_Over *this,Game_Manager *GM) {
  MLV_Font *font;
  int textbox_width = 0;
  int textbox_height=0;
  
  draw_button(&this->quit_btn);
  draw_button(&this->restart_btn);
  font = MLV_load_font ("resources/font/AdobeDevanagari-Bold.otf", 100);

  MLV_get_size_of_adapted_text_box_with_font("Game Over",font,5,&textbox_width,&textbox_height);

  MLV_draw_adapted_text_box_with_font ((GM->window.width - textbox_width)/2,
				       GM->window.field.posY,
				       "Game Over",
				       font,
				       5,
				       MLV_rgba(0,0,0,0),
				       MLV_COLOR_BROWN,
				       MLV_rgba(0,0,0,0),
				       MLV_TEXT_CENTER); 

  MLV_update_window();
}



/* Dessine les bases alliés et ennemies. */
void draw_home(Game_Manager *GM, Texture_Manager *TM) {
  MLV_draw_image(TM->friend_home_background,GM->window.friend_home.posX, GM->window.friend_home.posY);
  
  MLV_draw_image(TM->enemy_home_background, GM->window.enemy_home.posX, GM->window.friend_home.posY);
}



/* Dessine les spawners alliés. */
void draw_friend_spawner(Game_Manager *GM, Texture_Manager *TM) {
  int i;
  int textbox_width = 0;
  int textbox_height=0;
  MLV_Color Color;
  MLV_draw_image(TM->friend_spawner_background,GM->window.friend_spawner.posX, GM->window.friend_spawner.posY);
  
  if (GM->p1.is_deleting){MLV_draw_filled_rectangle(GM->window.field.posX + GM->window.rectsize * (NB_COLUMNS-1), 0, GM->window.rectsize, GM->window.friend_spawner.height, MLV_COLOR_BLUE);}

  MLV_draw_image(TM->delete_friend_img, GM->window.friend_spawner.posX + (NB_COLUMNS-1)*GM->window.rectsize+GM->window.rectsize/4 , GM->window.friend_spawner.posY+GM->window.rectsize/4);
  
  for (i=0;i<NB_FRIENDS;i++){
    Color = (GM->p1.money >= GM->friend_spawners[i].price) ? MLV_COLOR_GREEN : MLV_COLOR_RED;
    if (GM->p1.chosen_friend == i) {
      MLV_draw_filled_rectangle(GM->window.field.posX + GM->window.rectsize * (i+1), 0, GM->window.rectsize, GM->window.friend_spawner.height, Color);
    }
    
    MLV_draw_image(TM->friend_spawners_imgs[i],GM->window.friend_spawner.posX + (i+1)*GM->window.rectsize,GM->window.friend_spawner.posY);

    MLV_get_size_of_adapted_text_box(GM->friend_spawners[i].price_str,5,&textbox_width,&textbox_height);

    MLV_draw_adapted_text_box((GM->window.friend_spawner.posX + (i+1)*GM->window.rectsize) + ((GM->window.rectsize) - textbox_width)/2,
			      GM->window.friend_spawner.height - textbox_height,
			      GM->friend_spawners[i].price_str,
			      5,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_BLACK,
			      Color,
			      MLV_TEXT_CENTER);

  }
}



/* Dessine les statistiques du joueur 1. */
void draw_friend_stats(Game_Manager *GM,Texture_Manager *TM){
  int textbox_width = 0;
  int textbox_height=0;
  int i;

  MLV_draw_image(TM->score_img,GM->window.friend_spawner.posX, GM->window.friend_spawner.height - GM->window.rectsize/4 );
  
  MLV_get_size_of_adapted_text_box (GM->p1.money_str,5,&textbox_width,&textbox_height);
  MLV_draw_text_box((GM->window.friend_spawner.posX) + ((GM->window.rectsize) - textbox_width)/2,
		    GM->window.friend_spawner.height  - (textbox_height + textbox_height/4),
		    GM->window.rectsize/2,
		    textbox_height,
		    GM->p1.money_str,
		    5,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_BLACK,
		    MLV_COLOR_GOLD2,
		    MLV_TEXT_LEFT,
		    MLV_HORIZONTAL_CENTER,
		    MLV_VERTICAL_CENTER);
  
  MLV_get_size_of_adapted_text_box_with_font(GM->p1.name,TM->font,5,&textbox_width,&textbox_height);

  MLV_draw_adapted_text_box_with_font(
				      (GM->window.friend_spawner.posX) + ((GM->window.rectsize) - textbox_width)/2,
				      GM->window.friend_spawner.posY + textbox_height,
				      GM->p1.name,
				      TM->font,
				      5,
				      MLV_rgba(0,0,0,0),
				      MLV_COLOR_BLACK,
				      MLV_rgba(0,0,0,0),
				      MLV_TEXT_CENTER);
  
   for(i=0;i<GM->p1.life;i++){
     MLV_draw_image(TM->life_friend_img, (GM->window.friend_spawner.posX + ((GM->window.rectsize - (GM->p1.life * GM->window.rectsize)/6)/2) + (i*GM->window.rectsize)/6), GM->window.friend_spawner.height - (GM->window.rectsize/2));

   }
}



/* Dessine les statistiques du joueur 2. */
void draw_enemy_stats(Game_Manager *GM,Texture_Manager *TM){
  int textbox_width = 0;
  int textbox_height=0;

  MLV_draw_image(TM->score_img,GM->window.enemy_spawner.posX, GM->window.enemy_spawner.height - GM->window.rectsize/4 );
  
  MLV_get_size_of_adapted_text_box (GM->p2.money_str,5,&textbox_width,&textbox_height);
  MLV_draw_adapted_text_box(GM->window.enemy_spawner.posX + ((GM->window.rectsize) - textbox_width)/2,
			    GM->window.enemy_spawner.posY + GM->window.enemy_spawner.height - textbox_height,
			    GM->p2.money_str,
			    5,
			    MLV_COLOR_BLACK,
			    MLV_COLOR_BLACK,
			    MLV_COLOR_YELLOW,
			    MLV_TEXT_CENTER);
  
  MLV_get_size_of_adapted_text_box_with_font(GM->p2.name,TM->font,5,&textbox_width,&textbox_height);
  
  MLV_draw_adapted_text_box_with_font(
				      (GM->window.enemy_spawner.posX) + ((GM->window.rectsize) - textbox_width)/2,
				      GM->window.enemy_spawner.posY + textbox_height,
				      GM->p2.name,
				      TM->font,
				      5,
				      MLV_rgba(0,0,0,0),
				      MLV_COLOR_BLACK,
				      MLV_rgba(0,0,0,0),
				      MLV_TEXT_CENTER);
}



/* Dessine les spawners ennemies. */
void draw_enemy_spawner(Game_Manager *GM, Texture_Manager *TM) {
  int i;
  int textbox_width =0;
  int textbox_height=0;
  MLV_Color Color;
  MLV_draw_image(TM->enemy_spawner_background,GM->window.enemy_spawner.posX, GM->window.enemy_spawner.posY);
  for (i=0;i<NB_ENEMIES;i++){
    Color = (GM->p2.money >= GM->enemy_spawners[i].price) ? MLV_COLOR_GREEN : MLV_COLOR_RED;
    if (GM->p2.chosen_enemy == i) {
      MLV_draw_filled_rectangle(GM->window.field.posX + GM->window.rectsize * (i+1), GM->window.enemy_spawner.posY, GM->window.rectsize, GM->window.enemy_spawner.height, Color);
    }
    MLV_draw_image(TM->enemy_spawners_imgs[i],GM->window.enemy_spawner.posX + (i+1)*GM->window.rectsize,GM->window.enemy_spawner.posY);

    MLV_get_size_of_adapted_text_box (GM->enemy_spawners[i].price_str,5,&textbox_width,&textbox_height);    
    MLV_draw_adapted_text_box((GM->window.enemy_spawner.posX + (i+1)*GM->window.rectsize) + ((GM->window.rectsize) - textbox_width)/2,
			      GM->window.enemy_spawner.posY + GM->window.enemy_spawner.height - textbox_height,
			      GM->enemy_spawners[i].price_str,
			      5,
			      MLV_COLOR_BLACK,
			      MLV_COLOR_BLACK,
			      Color,
			      MLV_TEXT_CENTER);  
  }
}



/* Dessine le terrain de jeu. */
void draw_field(Game_Manager *GM, Texture_Manager *TM) {
  int i, j;
  MLV_Image *img;
  for (i=0; i<NB_ROWS; i++) {
    for (j=0; j<NB_COLUMNS; j++) {
      img = ((i+j)%2) ? TM->field_light_grass_img : TM->field_dark_grass_img;
      MLV_draw_image(img, GM->window.field.posX + j*GM->window.rectsize, GM->window.field.posY + i*GM->window.rectsize);
    }
  }
}



/* Dessine toute la fenetre. */
void draw_window(Game_Manager *GM, Texture_Manager *TM) {
  MLV_Color Color;

  draw_home(GM, TM);
  
  if (GM->gamemode == MULTI) {
    draw_enemy_spawner(GM, TM);
    draw_enemy_stats(GM,TM);
  }
  draw_friend_spawner(GM,TM);
  draw_friend_stats(GM,TM);

  draw_field(GM, TM);
  if(GM->gamemode == SOLO){return;}

  Color = (GM->p2.money >= GM->enemy_spawners[GM->p2.chosen_enemy].price) ? MLV_COLOR_GREEN : MLV_COLOR_RED;
  MLV_draw_filled_rectangle(GM->window.field.posX + GM->window.rectsize * (NB_COLUMNS-1), GM->window.field.posY + GM->window.rectsize * GM->p2.chosen_row, GM->window.rectsize, GM->window.rectsize, Color);
}
