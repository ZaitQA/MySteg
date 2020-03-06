#include "save.h"
#include <zlib.h>

void save(SDL_Surface* surface)
{
    IMG_SavePNG("text.png", surface, Z_NO_COMPRESSION);
}
