hexdumper:  util.c hexdumper.c util.h rom_structs.h constants.h
	gcc -Wall --std=c11 -o hexdumper util.c hexdumper.c

all: hexdumper

clean:
	rm -f *.o hexdumper