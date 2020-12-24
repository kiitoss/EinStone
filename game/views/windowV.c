#include "../gameHeader.h"
#include "../makhead.h"

void draw_home(Game_Manager *GM, Texture_Manager *TM) {
   MLV_draw_image(TM->friend_home_background,GM->window.friend_home.posX, GM->window.friend_home.posY);
  
   MLV_draw_image(TM->enemy_home_background, GM->window.enemy_home.posX, GM->window.friend_home.posY);
}

void draw_friend_spawner(Game_Manager *GM, Texture_Manager *TM) {
  int i;
  int textbox_width = 0;
  int textbox_height=0;
  MLV_Color Color;
  MLV_draw_image(TM->friend_spawner_background,GM->window.friend_spawner.posX, GM->window.friend_spawner.posY);
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
  
  /*MLV_get_size_of_adapted_text_box("DELETE",5,&textbox_width,&textbox_height);

  MLV_draw_adapted_text_box_with_font(GM->window.friend_spawner.posX + ((NB_COLUMNS-1) * GM->window.rectsize) + GM->window.rectsize/4,
				      GM->window.friend_spawner.height - textbox_height,
				      "DELETE",
				      TM->font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_FIREBRICK2,
				      MLV_TEXT_CENTER);
*/
}

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
  
  GM->p1.name = "FRIENDSjuyfjyfjjhhhhhhhhhh";
  MLV_get_size_of_adapted_text_box(GM->p1.name,5,&textbox_width,&textbox_height);
  
  MLV_draw_adapted_text_box_with_font(
				      (GM->window.friend_spawner.posX) + ((GM->window.rectsize) - textbox_width)/2,
				      GM->window.friend_spawner.posY + textbox_height,
				      GM->p1.name,
				      TM->font,
				      5,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_BLACK,
				      MLV_COLOR_WHITE,
				      MLV_TEXT_CENTER);
  
  
   for(i=0;i<GM->p1.life;i++){
     MLV_draw_image(TM->life_friend_img, (GM->window.friend_spawner.posX + ((GM->window.rectsize - (GM->p1.life * GM->window.rectsize)/6)/2) + (i*GM->window.rectsize)/6), GM->window.friend_spawner.height - (GM->window.rectsize/2));

   }
}
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
  GM->p2.name = "ENEMIES";
  MLV_get_size_of_adapted_text_box(GM->p2.name,5,&textbox_width,&textbox_height);
  MLV_draw_adapted_text_box_with_font(
				      (GM->window.enemy_spawner.posX) + ((GM->window.rectsize) - textbox_width)/2,
				      GM->window.enemy_spawner.posY + textbox_height,
				      GM->p2.name,
				      TM->font,
				      5,
				      MLV_rgba(0,0,0,0),
				      MLV_rgba(0,0,0,0),
				      MLV_rgba(0,0,0,0),
				      MLV_TEXT_CENTER);
}

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


/* GLOBAL */
void draw_window(Game_Manager *GM, Texture_Manager *TM) {
  draw_home(GM, TM);
  if (GM->gamemode == MULTI) {
    draw_enemy_spawner(GM, TM);
    draw_enemy_stats(GM,TM);
  }
  draw_friend_spawner(GM,TM);
  draw_friend_stats(GM,TM);

  draw_field(GM, TM);
  
  MLV_draw_filled_rectangle(GM->window.field.posX + GM->window.rectsize * (NB_COLUMNS-1), GM->window.field.posY + GM->window.rectsize * GM->p2.chosen_row, GM->window.rectsize, GM->window.rectsize, MLV_COLOR_GREEN);
}
