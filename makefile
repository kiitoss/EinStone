CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3
headers = ./sources/headers/global_header.h ./sources/headers/GUI.h ./sources/headers/game.h ./sources/headers/menu.h ./sources/headers/functions.h

all: einstone clean

einstone: button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_GM.o init_IA.o init_SM.o init_TM.o init_spawner.o init_window.o draw_game.o draw_object.o draw_window.o game.o main_page.o newgame_page.o resume_page.o score_page.o meth_main_page.o meth_newgame_page.o meth_resume_page.o meth_score_page.o draw_menu.o menu.o save.o `pkg-config --libs-only-l MLV` -o einstone

button.o: ./sources/GUI/button.c $(headers)
	$(CC) $(CFLAGS) ./sources/GUI/button.c -c -I ./

general.o: ./sources/GUI/general.c $(headers)
	$(CC) $(CFLAGS) ./sources/GUI/general.c -c -I ./

input.o: ./sources/GUI/input.c $(headers)
	$(CC) $(CFLAGS) ./sources/GUI/input.c -c -I ./

label.o: ./sources/GUI/label.c $(headers)
	$(CC) $(CFLAGS) ./sources/GUI/label.c -c -I ./

IA.o: ./sources/game/controllers/IA.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/IA.c -c -I ./

enemy.o: ./sources/game/controllers/enemy.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/enemy.c -c -I ./

friend.o: ./sources/game/controllers/friend.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/friend.c -c -I ./

player.o: ./sources/game/controllers/player.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/player.c -c -I ./

pop.o: ./sources/game/controllers/pop.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/pop.c -c -I ./

row.o: ./sources/game/controllers/row.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/controllers/row.c -c -I ./

init_GM.o: ./sources/game/initializers/init_GM.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_GM.c -c -I ./

init_IA.o: ./sources/game/initializers/init_IA.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_IA.c -c -I ./

init_SM.o: ./sources/game/initializers/init_SM.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_SM.c -c -I ./

init_TM.o: ./sources/game/initializers/init_TM.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_TM.c -c -I ./

init_spawner.o: ./sources/game/initializers/init_spawner.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_spawner.c -c -I ./

init_window.o: ./sources/game/initializers/init_window.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/initializers/init_window.c -c -I ./

draw_game.o: ./sources/game/views/draw_game.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/views/draw_game.c -c -I ./

draw_object.o: ./sources/game/views/draw_object.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/views/draw_object.c -c -I ./

draw_window.o: ./sources/game/views/draw_window.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/views/draw_window.c -c -I ./

game.o: ./sources/game/game.c $(headers)
	$(CC) $(CFLAGS) ./sources/game/game.c -c -I ./

main_page.o: ./sources/menu/controllers/main_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/controllers/main_page.c -c -I ./

newgame_page.o: ./sources/menu/controllers/newgame_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/controllers/newgame_page.c -c -I ./

resume_page.o: ./sources/menu/controllers/resume_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/controllers/resume_page.c -c -I ./

score_page.o: ./sources/menu/controllers/score_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/controllers/score_page.c -c -I ./

meth_main_page.o: ./sources/menu/methods/meth_main_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/methods/meth_main_page.c -c -I ./

meth_newgame_page.o: ./sources/menu/methods/meth_newgame_page.c
	$(CC) $(CFLAGS) ./sources/menu/methods/meth_newgame_page.c -c -I ./

meth_resume_page.o: ./sources/menu/methods/meth_resume_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/methods/meth_resume_page.c -c -I ./

meth_score_page.o: ./sources/menu/methods/meth_score_page.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/methods/meth_score_page.c -c -I ./

draw_menu.o: ./sources/menu/views/draw_menu.c $(headers)
	$(CC) $(CFLAGS) ./sources/menu/views/draw_menu.c -c -I ./

menu.o: ./sources/menu/menu.c
	$(CC) $(CFLAGS) ./sources/menu/menu.c -c -I ./

save.o: ./sources/save/save.c $(headers)
	$(CC) $(CFLAGS) ./sources/save/save.c -c -I ./

clean:
	rm -rf *.o
