CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: button.o general.o input.o label.o resumeSection.o IAC.o enemyC.o friendC.o gameC.o playerC.o popC.o rowC.o animationM.o gameManagerM.o soundManager.o spawnerM.o textureManagerM.o windowM.o gameV.o windowV.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o mainPageM.o newgamePageM.o resumePageM.o pageV.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` button.o general.o input.o label.o resumeSection.o IAC.o enemyC.o friendC.o gameC.o playerC.o popC.o rowC.o animationM.o gameManagerM.o soundManager.o spawnerM.o textureManagerM.o windowM.o gameV.o windowV.o mainPageC.o menuC.o newGamePageC.o resumePageC.o scorePageC.o mainPageM.o newgamePageM.o resumePageM.o pageV.o `pkg-config --libs-only-l MLV` -o output

button.o: ./GUI/button.c
	$(CC) $(CFLAGS) ./GUI/button.c -c -I ./

general.o: ./GUI/general.c
	$(CC) $(CFLAGS) ./GUI/general.c -c -I ./

input.o: ./GUI/input.c
	$(CC) $(CFLAGS) ./GUI/input.c -c -I ./

label.o: ./GUI/label.c
	$(CC) $(CFLAGS) ./GUI/label.c -c -I ./

resumeSection.o: ./GUI/resumeSection.c
	$(CC) $(CFLAGS) ./GUI/resumeSection.c -c -I ./

IAC.o: ./game/controllers/IAC.c
	$(CC) $(CFLAGS) ./game/controllers/IAC.c -c -I ./

enemyC.o: ./game/controllers/enemyC.c
	$(CC) $(CFLAGS) ./game/controllers/enemyC.c -c -I ./

friendC.o: ./game/controllers/friendC.c
	$(CC) $(CFLAGS) ./game/controllers/friendC.c -c -I ./

gameC.o: ./game/controllers/gameC.c
	$(CC) $(CFLAGS) ./game/controllers/gameC.c -c -I ./

playerC.o: ./game/controllers/playerC.c
	$(CC) $(CFLAGS) ./game/controllers/playerC.c -c -I ./

popC.o: ./game/controllers/popC.c
	$(CC) $(CFLAGS) ./game/controllers/popC.c -c -I ./

rowC.o: ./game/controllers/rowC.c
	$(CC) $(CFLAGS) ./game/controllers/rowC.c -c -I ./

animationM.o: ./game/models/animationM.c
	$(CC) $(CFLAGS) ./game/models/animationM.c -c -I ./

gameManagerM.o: ./game/models/gameManagerM.c
	$(CC) $(CFLAGS) ./game/models/gameManagerM.c -c -I ./

soundManager.o: ./game/models/soundManager.c
	$(CC) $(CFLAGS) ./game/models/soundManager.c -c -I ./

spawnerM.o: ./game/models/spawnerM.c
	$(CC) $(CFLAGS) ./game/models/spawnerM.c -c -I ./

textureManagerM.o: ./game/models/textureManagerM.c
	$(CC) $(CFLAGS) ./game/models/textureManagerM.c -c -I ./

windowM.o: ./game/models/windowM.c
	$(CC) $(CFLAGS) ./game/models/windowM.c -c -I ./

gameV.o: ./game/views/gameV.c
	$(CC) $(CFLAGS) ./game/views/gameV.c -c -I ./

windowV.o: ./game/views/windowV.c
	$(CC) $(CFLAGS) ./game/views/windowV.c -c -I ./

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

pageV.o: ./menu/views/pageV.c
	$(CC) $(CFLAGS) ./menu/views/pageV.c -c -I ./

clean:
	rm -rf *.o
