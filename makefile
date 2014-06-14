hexdumper: hexdumper.c rom_structs.h constants.h
	gcc -Wall -o hexdumper hexdumper.c

all: hexdumper