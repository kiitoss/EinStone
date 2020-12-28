#include "../global_structures.h"
#include "../global_functions.h"

/* GLOBAL */
void set_GMG(GM_list_games GMG) {
  int i;
  FILE *games = fopen("./resources/games.bin", "rb");

  
  if (games == NULL) {
    for (i=0; i<SAVED_GAMES; i++) {
      GMG[i].id = 0;
    }
  }
  else {
    for (i=0; i<SAVED_GAMES; i++) {
      if (!fread(&GMG[i], sizeof(Game_Manager), 1, games)) {
	printf("--> erreur lors de la lecture des parties.\n");
      }
    }
    fclose(games);
  }
}




/* GLOBAL */
void write_GMG(GM_list_games GMG) {
  int i;
  FILE *games = fopen("./resources/games.bin", "wb");
  for (i=0; i<SAVED_GAMES; i++) {
    fwrite(&GMG[i], sizeof(Game_Manager), 1, games);
  }
  fclose(games);
}


/* GLOBAL */
void set_GMS(GM_list_scores GMS) {
  int i;
  FILE *scores = fopen("./resources/scores.bin", "rb");

  
  if (scores == NULL) {
    for (i=0; i<SAVED_SCORES; i++) {
      GMS[i].id = 0;
      GMS[i].p1.score = 0;
    }
  }
  else {
    for (i=0; i<SAVED_SCORES; i++) {
      if (!fread(&GMS[i], sizeof(Game_Manager), 1, scores)) {
	printf("--> erreur lors de la lecture des scores.\n");
      }
    }
    fclose(scores);
  }
}




/* GLOBAL */
void write_GMS(GM_list_scores GMS) {
  int i;
  FILE *scores = fopen("./resources/scores.bin", "wb");
  for (i=0; i<SAVED_SCORES; i++) {
    fwrite(&GMS[i], sizeof(Game_Manager), 1, scores);
  }
  fclose(scores);
}


/* GLOBAL */
void remove_saved_game(int id_game) {
  GM_list_games GMG;
  int i;
  
  if (id_game == 0) {
    return;
  }
  
  set_GMG(GMG);
  for (i=0; i<SAVED_GAMES; i++) {
    if (GMG[i].id == id_game) {
      for (i=i; i<SAVED_GAMES-1; i++) {
	GMG[i] = GMG[i+1];
      }
      GMG[SAVED_GAMES-1].id = 0;
      break;
    }
  }
  write_GMG(GMG);
}



/* GLOBAL */
int get_unique_id() {
  GM_list_scores GMS;
  GM_list_games GMG;
  int id = 0;
  int i;
  bool is_free_id = false;

  set_GMS(GMS);
  set_GMG(GMG);
 
  while (!is_free_id) {
    id++;
    is_free_id = true;
    for (i=0; i<SAVED_SCORES; i++) {
      if (GMS[i].id == id) {
	is_free_id = false;
	break;
      }
    }
    if (!is_free_id) {continue;}
    for (i=0; i<SAVED_GAMES; i++) {
      if (GMG[i].id == id) {
	is_free_id = false;
	break;
      }
    }
  }

  return id;
}





/* Sauvegarde la partie en cours avant de quitter */
/* GLOBAL */
void save_score(Game_Manager *GM, int time) {
  GM_list_scores GMS;
  Game_Manager temp_GM, temp_GM2;
  int i;

  GM->duration += MLV_get_time() - time;

  set_GMS(GMS);

  if (GM->id == 0) {
    GM->id = get_unique_id();
  }

  for (i=0; i<SAVED_SCORES; i++) {
    if (GMS[i].p1.score <= GM->p1.score) {
      temp_GM2 = *GM;
      for (i=i; i<SAVED_SCORES; i++) {
	temp_GM = GMS[i];
	GMS[i] = temp_GM2;
	temp_GM2 = temp_GM;
      }
    }
  }

  write_GMS(GMS);
}



/* Sauvegarde la partie en cours avant de quitter */
/* GLOBAL */
void save_game(Game_Manager *GM, int time) {
  GM_list_games GMG;
  int i;

  GM->duration += MLV_get_time() - time;

  set_GMG(GMG);

  if (GM->id == 0) {
    GM->id = get_unique_id();
    for (i=SAVED_GAMES-1; i>0; i--) {
      GMG[i] = GMG[i-1];
    }
    GMG[0] = *GM;
  }
  else {
    for (i=0; i<SAVED_GAMES; i++) {
      if (GMG[i].id == GM->id) {
	GMG[i] = *GM;
	break;
      }
    }
  }

  write_GMG(GMG);
}
