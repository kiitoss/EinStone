CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3
headers = ./project/headers/global_header.h ./project/headers/GUI.h ./project/headers/game.h ./project/headers/menu.h ./project/headers/functions.h

all: einstone clean

einstone: button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o `pkg-config --libs-only-l MLV` -o einstone

button.o: ./project/GUI/button.c $(headers)
	$(CC) $(CFLAGS) ./project/GUI/button.c -c -I ./

general.o: ./project/GUI/general.c $(headers)
	$(CC) $(CFLAGS) ./project/GUI/general.c -c -I ./

input.o: ./project/GUI/input.c $(headers)
	$(CC) $(CFLAGS) ./project/GUI/input.c -c -I ./

label.o: ./project/GUI/label.c $(headers)
	$(CC) $(CFLAGS) ./project/GUI/label.c -c -I ./

IA.o: ./project/game/controllers/IA.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/IA.c -c -I ./

enemy.o: ./project/game/controllers/enemy.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/enemy.c -c -I ./

friend.o: ./project/game/controllers/friend.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/friend.c -c -I ./

player.o: ./project/game/controllers/player.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/player.c -c -I ./

pop.o: ./project/game/controllers/pop.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/pop.c -c -I ./

row.o: ./project/game/controllers/row.c $(headers)
	$(CC) $(CFLAGS) ./project/game/controllers/row.c -c -I ./

init_GM.o: ./project/game/initializers/init_GM.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_GM.c -c -I ./

init_IA.o: ./project/game/initializers/init_IA.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_IA.c -c -I ./

init_SM.o: ./project/game/initializers/init_SM.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_SM.c -c -I ./

init_TM.o: ./project/game/initializers/init_TM.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_TM.c -c -I ./

init_spawner.o: ./project/game/initializers/init_spawner.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_spawner.c -c -I ./

init_window.o: ./project/game/initializers/init_window.c $(headers)
	$(CC) $(CFLAGS) ./project/game/initializers/init_window.c -c -I ./

draw_game.o: ./project/game/views/draw_game.c $(headers)
	$(CC) $(CFLAGS) ./project/game/views/draw_game.c -c -I ./

draw_object.o: ./project/game/views/draw_object.c $(headers)
	$(CC) $(CFLAGS) ./project/game/views/draw_object.c -c -I ./

draw_window.o: ./project/game/views/draw_window.c $(headers)
	$(CC) $(CFLAGS) ./project/game/views/draw_window.c -c -I ./

game.o: ./project/game/game.c $(headers)
	$(CC) $(CFLAGS) ./project/game/game.c -c -I ./

main_page.o: ./project/menu/controllers/main_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/controllers/main_page.c -c -I ./

newgame_page.o: ./project/menu/controllers/newgame_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/controllers/newgame_page.c -c -I ./

resume_page.o: ./project/menu/controllers/resume_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/controllers/resume_page.c -c -I ./

score_page.o: ./project/menu/controllers/score_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/controllers/score_page.c -c -I ./

meth_main_page.o: ./project/menu/methods/meth_main_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/methods/meth_main_page.c -c -I ./

meth_newgame_page.o: ./project/menu/methods/meth_newgame_page.c
	$(CC) $(CFLAGS) ./project/menu/methods/meth_newgame_page.c -c -I ./

meth_resume_page.o: ./project/menu/methods/meth_resume_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/methods/meth_resume_page.c -c -I ./

meth_score_page.o: ./project/menu/methods/meth_score_page.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/methods/meth_score_page.c -c -I ./

draw_menu.o: ./project/menu/views/draw_menu.c $(headers)
	$(CC) $(CFLAGS) ./project/menu/views/draw_menu.c -c -I ./

menu.o: ./project/menu/menu.c
	$(CC) $(CFLAGS) ./project/menu/menu.c -c -I ./

save.o: ./project/save/save.c $(headers)
	$(CC) $(CFLAGS) ./project/save/save.c -c -I ./

clean:
	rm -rf *.o
