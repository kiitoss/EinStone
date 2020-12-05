CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O3

all: output clean

output: mainC.o gameManagerM.o textureManagerM.o 
	$(CC) $(CFLAGS) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` mainC.o gameManagerM.o textureManagerM.o `pkg-config --libs-only-l MLV` -o output

mainC.o: ./game/controllers/mainC.c
	$(CC) $(CFLAGS) ./game/controllers/mainC.c -c -I ./

gameManagerM.o: ./game/models/gameManagerM.c
	$(CC) $(CFLAGS) ./game/models/gameManagerM.c -c -I ./

textureManagerM.o: ./game/models/textureManagerM.c
	$(CC) $(CFLAGS) ./game/models/textureManagerM.c -c -I ./

clean:
	rm -rf *.o
