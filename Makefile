CC = gcc -rdynamic
CPPFLAGS =  `pkg-config gtk+-3.0 --cflags sdl`
CFLAGS = -I src -Wall -Wextra -std=c99 -lpng -g -lz
LDLIBS = `pkg-config gtk+-3.0 --libs sdl` -lSDL_image -lm
SRC = */main.c  */*/*.c

all:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDLIBS) -o steg $(SRC)

clean:
	$(RM) $(OBJ) $(OBJ_TESTS) $(DEP) $(DEP_TESTS) steg text.png
