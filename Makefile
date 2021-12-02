CC = gcc
var = `pkg-config --cflags --libs gtk+-3.0`

main: main.c 
	@$(CC) -rdynamic $(var) main.c -o main

