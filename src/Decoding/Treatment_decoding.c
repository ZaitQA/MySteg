#include "Tools/tools.h"

void decode_wallpaper_in_string(SDL_Surface *surface, int coeff)
{
    int w;
    int h;
    w = surface->w;
    h = surface->h;
    int is_time = 0;
    char *letter = calloc(9, sizeof(char));
    char finish = 0;
    char verif = 0;
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
                if (!is_time)
                {
                    verif = strtol(letter, 0, 2);
                    is_time = 1;
                    z = 0;
                    continue;
                }
                finish = strtol(letter, 0, 2);
                if (finish == verif)
                {
                    free(letter);
                    return;
                }
                else
                    printf("%c", finish);
                z = 0;
            }
        }
    }
    free(letter);
}
