#include "../Tools/Tools.h"
#include "string_to_binary.h"


SDL_Surface *encode_binary_in_wallpaper(SDL_Surface *surface, struct encode *encode)
{
    int w;
    int h;
    w = surface->w;
    h = surface->h;
    for (int i = 0, z = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (encode[z].bin == NULL)
                return surface;
            Uint32 pixel = getpixel(surface, i, j);
            char *pixel_char = calloc(129, sizeof(char));
            pixel_char = my_itoa_base(pixel, pixel_char, "01");
            if (strlen(pixel_char) < 2)
            {
                pixel_char[0] = encode[z].bin[0];
                pixel_char[1] = encode[z].bin[1];
            }
            else
            {
                pixel_char[strlen(pixel_char) - 2] = encode[z].bin[0];
                pixel_char[strlen(pixel_char) - 1] = encode[z].bin[1];
            }
            Uint32 pixel_finish = my_atoi_base(pixel_char, "01");
            put_pixel(surface, i, j, pixel_finish);
            free(pixel_char);
            z++;
        }
    }
    return surface;
}
