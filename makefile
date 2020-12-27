CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_IA.o init_gameManager.o init_row.o init_soundManager.o init_spawner.o init_textureManager.o init_window.o game_view.o window_view.o game.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o mainPageM.o newgamePageM.o resumePageM.o scorePageM.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` button.o general.o input.o label.o IA.o enemy.o friend.o player.o pop.o row.o init_IA.o init_gameManager.o init_row.o init_soundManager.o init_spawner.o init_textureManager.o init_window.o game_view.o window_view.o game.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o mainPageM.o newgamePageM.o resumePageM.o scorePageM.o pageV.o `pkg-config --libs-only-l MLV` -o output

button.o: ./GUI/button.c
	$(CC) $(CFLAGS) ./GUI/button.c -c -I ./

general.o: ./GUI/general.c
	$(CC) $(CFLAGS) ./GUI/general.c -c -I ./

input.o: ./GUI/input.c
	$(CC) $(CFLAGS) ./GUI/input.c -c -I ./

label.o: ./GUI/label.c
	$(CC) $(CFLAGS) ./GUI/label.c -c -I ./

IA.o: ./game/controllers/IA.c
	$(CC) $(CFLAGS) ./game/controllers/IA.c -c -I ./

enemy.o: ./game/controllers/enemy.c
	$(CC) $(CFLAGS) ./game/controllers/enemy.c -c -I ./

friend.o: ./game/controllers/friend.c
	$(CC) $(CFLAGS) ./game/controllers/friend.c -c -I ./

player.o: ./game/controllers/player.c
	$(CC) $(CFLAGS) ./game/controllers/player.c -c -I ./

pop.o: ./game/controllers/pop.c
	$(CC) $(CFLAGS) ./game/controllers/pop.c -c -I ./

row.o: ./game/controllers/row.c
	$(CC) $(CFLAGS) ./game/controllers/row.c -c -I ./

init_IA.o: ./game/initializers/init_IA.c
	$(CC) $(CFLAGS) ./game/initializers/init_IA.c -c -I ./

init_gameManager.o: ./game/initializers/init_gameManager.c
	$(CC) $(CFLAGS) ./game/initializers/init_gameManager.c -c -I ./

init_row.o: ./game/initializers/init_row.c
	$(CC) $(CFLAGS) ./game/initializers/init_row.c -c -I ./

init_soundManager.o: ./game/initializers/init_soundManager.c
	$(CC) $(CFLAGS) ./game/initializers/init_soundManager.c -c -I ./

init_spawner.o: ./game/initializers/init_spawner.c
	$(CC) $(CFLAGS) ./game/initializers/init_spawner.c -c -I ./

init_textureManager.o: ./game/initializers/init_textureManager.c
	$(CC) $(CFLAGS) ./game/initializers/init_textureManager.c -c -I ./

init_window.o: ./game/initializers/init_window.c
	$(CC) $(CFLAGS) ./game/initializers/init_window.c -c -I ./

game_view.o: ./game/views/game_view.c
	$(CC) $(CFLAGS) ./game/views/game_view.c -c -I ./

window_view.o: ./game/views/window_view.c
	$(CC) $(CFLAGS) ./game/views/window_view.c -c -I ./

game.o: ./game/game.c
	$(CC) $(CFLAGS) ./game/game.c -c -I ./

mainPageC.o: ./menu/controllers/mainPageC.c
	$(CC) $(CFLAGS) ./menu/controllers/mainPageC.c -c -I ./

menuC.o: ./menu/controllers/menuC.c
	$(CC) $(CFLAGS) ./menu/controllers/menuC.c -c -I ./

newGamePageC.o: ./menu/controllers/newGamePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/newGamePageC.c -c -I ./

resumePageC.o: ./menu/controllers/resumePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/resumePageC.c -c -I ./

scorePageC.o: ./menu/controllers/scorePageC.c
	$(CC) $(CFLAGS) ./menu/controllers/scorePageC.c -c -I ./

mainPageM.o: ./menu/models/mainPageM.c
	$(CC) $(CFLAGS) ./menu/models/mainPageM.c -c -I ./

newgamePageM.o: ./menu/models/newgamePageM.c
	$(CC) $(CFLAGS) ./menu/models/newgamePageM.c -c -I ./

resumePageM.o: ./menu/models/resumePageM.c
	$(CC) $(CFLAGS) ./menu/models/resumePageM.c -c -I ./

scorePageM.o: ./menu/models/scorePageM.c
	$(CC) $(CFLAGS) ./menu/models/scorePageM.c -c -I ./

pageV.o: ./menu/views/pageV.c
	$(CC) $(CFLAGS) ./menu/views/pageV.c -c -I ./

clean:
	rm -rf *.o
