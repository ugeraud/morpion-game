CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
all: game


game: main.c
	@$(CC) -o $@ $^ $(LDFLAGS)

clean:
	@rm -rf *.o