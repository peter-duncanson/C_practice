#include <stdio.h>

int main(void)
{

    return 0;
}

CC=gcc
CFLAGS = -Wall

all: run

main: main.c
	@($(CC) $(CFLAGS)  main.c scratch.c -Wall -o app)

run:
	@(./app)

clean:
	@(rm app)
