#include "../Tools/Tools.h"
#include "binary_to_string.h"

void decode_wallpaper_in_string(SDL_Surface *surface, int coeff)
{
    int w;
    int h;
    w = surface->w;
    h = surface->h;
    char *letter = calloc(9, sizeof(char));
    for (int i = 0, z = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            Uint32 pixel = getpixel(surface, i, j);
            char *pixel_char = calloc(32 + 1, sizeof(char));
            pixel_char = my_itoa_base(pixel, pixel_char, "01");
            if (strcmp("1", pixel_char) == 0 && coeff == 2)
            {
                letter[z++] = '0';
                letter[z++] = '1';
            }
            else if (strcmp("0", pixel_char) == 0 && coeff == 2)
            {
                letter[z++] = '0';
                letter[z++] = '0';
            }
            else
            {
                for (int a = coeff, d = 0; a != 0; a--, z++, d++)
                {
                    letter[z] = pixel_char[strlen(pixel_char) - a];
                }
            }
            if (z == 8)
            {
                int temp = binary_to_string(letter);
                if (temp)
                    return;
                z = 0;
            }
        }
    }
    free(letter);
}
