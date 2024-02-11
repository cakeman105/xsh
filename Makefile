compile:
	gcc main.c utils/coreutils.c -Wall -pedantic -std=c99 -o xsh -fsanitize=address -g

run:
	./xsh