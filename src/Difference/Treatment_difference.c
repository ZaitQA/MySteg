#include "Tools/tools.h"

SDL_Surface *show_difference(SDL_Surface *surface, SDL_Surface *surface2)
{
    int w;
    int h;
    w = surface->w;
    h = surface->h;
    for (int i = 0, z = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            Uint32 pixel = getpixel(surface, i, j);
            Uint32 pixel2 = getpixel(surface2, i, j);
            Uint32 result = 0;
            if (pixel > pixel2)
                result = pixel - pixel2;
            else
                result = pixel2 - pixel;
            if (result != 0)
                result = 555555;
            put_pixel(surface2, i, j, result);
        }
    }
    return surface2;
}
