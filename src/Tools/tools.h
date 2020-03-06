#pragma once
#include <err.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y);
void put_pixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel);
int length(const char *str);
int number_digits(int n, int length);
char *my_itoa_base(int n, char *s, const char *base);
int search(char i, const char *base);
int my_atoi_base(const char *str, const char *base);
