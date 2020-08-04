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
    char *next = calloc(9, sizeof(char));
    for (int i = 0, z = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            Uint32 pixel = getpixel(surface, i, j);
            char *pixel_char = calloc(129, sizeof(char));
            pixel_char = my_itoa_base(pixel, pixel_char, "01");
            int len_pixel = strlen(pixel_char);
            //printf("decoding -> %s\n", pixel_char);
            if (len_pixel < coeff)
            {
                int zero_diff = coeff - len_pixel;
                for (int e = 0; e < zero_diff; e++)
                    letter[z++] = '0';
                for (int f = 0; f < len_pixel; f++)
                    letter[z++] = pixel_char[f];
            }
            else
            {
                for (int a = coeff, d = 0; a != 0; a--, d++, z++)
                {
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
                                printf("\n");
                                return;
                            }
                            else
                                printf("%c", finish);
                            z = 0;
                        }
                        letter[z] = pixel_char[len_pixel - a];
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
                    printf("\n");
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
