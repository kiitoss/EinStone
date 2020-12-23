CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: windowV.o gameV.o goldM.o soundManager.o rowM.o textureManagerM.o shotM.o playerM.o friendM.o gameManagerM.o windowM.o enemyM.o animationM.o spawnerM.o mainC.o friendC.o playerC.o popC.o enemyC.o rowC.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` windowV.o gameV.o goldM.o soundManager.o rowM.o textureManagerM.o shotM.o playerM.o friendM.o gameManagerM.o windowM.o enemyM.o animationM.o spawnerM.o mainC.o friendC.o playerC.o popC.o enemyC.o rowC.o `pkg-config --libs-only-l MLV` -o output

windowV.o: windowV.c
	$(CC) $(CFLAGS) windowV.c -c -I ./

gameV.o: gameV.c
	$(CC) $(CFLAGS) gameV.c -c -I ./

goldM.o: goldM.c
	$(CC) $(CFLAGS) goldM.c -c -I ./

soundManager.o: soundManager.c
	$(CC) $(CFLAGS) soundManager.c -c -I ./

rowM.o: rowM.c
	$(CC) $(CFLAGS) rowM.c -c -I ./

textureManagerM.o: textureManagerM.c
	$(CC) $(CFLAGS) textureManagerM.c -c -I ./

shotM.o: shotM.c
	$(CC) $(CFLAGS) shotM.c -c -I ./

playerM.o: playerM.c
	$(CC) $(CFLAGS) playerM.c -c -I ./

friendM.o: friendM.c
	$(CC) $(CFLAGS) friendM.c -c -I ./

gameManagerM.o: gameManagerM.c
	$(CC) $(CFLAGS) gameManagerM.c -c -I ./

windowM.o: windowM.c
	$(CC) $(CFLAGS) windowM.c -c -I ./

enemyM.o: enemyM.c
	$(CC) $(CFLAGS) enemyM.c -c -I ./

animationM.o: animationM.c
	$(CC) $(CFLAGS) animationM.c -c -I ./

spawnerM.o: spawnerM.c
	$(CC) $(CFLAGS) spawnerM.c -c -I ./

mainC.o: mainC.c
	$(CC) $(CFLAGS) mainC.c -c -I ./

friendC.o: friendC.c
	$(CC) $(CFLAGS) friendC.c -c -I ./

playerC.o: playerC.c
	$(CC) $(CFLAGS) playerC.c -c -I ./

popC.o: popC.c
	$(CC) $(CFLAGS) popC.c -c -I ./

enemyC.o: enemyC.c
	$(CC) $(CFLAGS) enemyC.c -c -I ./

rowC.o: rowC.c
	$(CC) $(CFLAGS) rowC.c -c -I ./

clean:
	rm -rf *.o
