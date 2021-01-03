CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3
headers = ./headers/global_header.h ./headers/GUI.h ./headers/game.h ./headers/menu.h ./headers/functions.h

all: einstone clean

einstone: button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o `pkg-config --libs-only-l MLV` -o einstone

button.o: ./GUI/button.c $(headers)
	$(CC) $(CFLAGS) ./GUI/button.c -c -I ./

general.o: ./GUI/general.c $(headers)
	$(CC) $(CFLAGS) ./GUI/general.c -c -I ./

input.o: ./GUI/input.c $(headers)
	$(CC) $(CFLAGS) ./GUI/input.c -c -I ./

label.o: ./GUI/label.c $(headers)
	$(CC) $(CFLAGS) ./GUI/label.c -c -I ./

IA.o: ./game/controllers/IA.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/IA.c -c -I ./

enemy.o: ./game/controllers/enemy.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/enemy.c -c -I ./

friend.o: ./game/controllers/friend.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/friend.c -c -I ./

player.o: ./game/controllers/player.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/player.c -c -I ./

pop.o: ./game/controllers/pop.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/pop.c -c -I ./

row.o: ./game/controllers/row.c $(headers)
	$(CC) $(CFLAGS) ./game/controllers/row.c -c -I ./

init_GM.o: ./game/initializers/init_GM.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_GM.c -c -I ./

init_IA.o: ./game/initializers/init_IA.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_IA.c -c -I ./

init_SM.o: ./game/initializers/init_SM.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_SM.c -c -I ./

init_TM.o: ./game/initializers/init_TM.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_TM.c -c -I ./

init_spawner.o: ./game/initializers/init_spawner.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_spawner.c -c -I ./

init_window.o: ./game/initializers/init_window.c $(headers)
	$(CC) $(CFLAGS) ./game/initializers/init_window.c -c -I ./

draw_game.o: ./game/views/draw_game.c $(headers)
	$(CC) $(CFLAGS) ./game/views/draw_game.c -c -I ./

draw_object.o: ./game/views/draw_object.c $(headers)
	$(CC) $(CFLAGS) ./game/views/draw_object.c -c -I ./

draw_window.o: ./game/views/draw_window.c $(headers)
	$(CC) $(CFLAGS) ./game/views/draw_window.c -c -I ./

game.o: ./game/game.c $(headers)
	$(CC) $(CFLAGS) ./game/game.c -c -I ./

main_page.o: ./menu/controllers/main_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/controllers/main_page.c -c -I ./

newgame_page.o: ./menu/controllers/newgame_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/controllers/newgame_page.c -c -I ./

resume_page.o: ./menu/controllers/resume_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/controllers/resume_page.c -c -I ./

score_page.o: ./menu/controllers/score_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/controllers/score_page.c -c -I ./

meth_main_page.o: ./menu/methods/meth_main_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/methods/meth_main_page.c -c -I ./

meth_newgame_page.o: ./menu/methods/meth_newgame_page.c
	$(CC) $(CFLAGS) ./menu/methods/meth_newgame_page.c -c -I ./

meth_resume_page.o: ./menu/methods/meth_resume_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/methods/meth_resume_page.c -c -I ./

meth_score_page.o: ./menu/methods/meth_score_page.c $(headers)
	$(CC) $(CFLAGS) ./menu/methods/meth_score_page.c -c -I ./

draw_menu.o: ./menu/views/draw_menu.c $(headers)
	$(CC) $(CFLAGS) ./menu/views/draw_menu.c -c -I ./

menu.o: ./menu/menu.c
	$(CC) $(CFLAGS) ./menu/menu.c -c -I ./

save.o: ./save/save.c $(headers)
	$(CC) $(CFLAGS) ./save/save.c -c -I ./

clean:
	rm -rf *.o
