CC = gcc -rdynamic

CPPFLAGS =  `pkg-config gtk+-3.0 --cflags sdl` -MMD

CFLAGS = -Wall -Wextra -std=c99 -g -lpng -lz

LDFLAGS =

LDLIBS= `pkg-config gtk+-3.0 --libs sdl` -lSDL_image -lm

SRC= Encoding/*.c Display/*.c Tools/*.c Decoding/*.c Difference/*.c main.c

all:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDLIBS) -o steg $(SRC)

clean:
	$(RM) $(OBJ) $(OBJ_TESTS) $(DEP) $(DEP_TESTS) steg
