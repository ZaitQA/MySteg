#include "Tools/tools.h"
#include "Encoding/string_to_binary.h"
#include <stdio.h>

SDL_Surface *encode_binary_in_wallpaper(SDL_Surface *surface,
        struct encode *encode, int coeff)
{
    int w;
    int h;
    w = surface->w;
    h = surface->h;
    int is_finished = 0;
    for (int i = 0, z = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (encode[z].bin == NULL)
                return surface;
            Uint32 pixel = getpixel(surface, i, j);
            char *pixel_char = calloc(129, sizeof(char));
            pixel_char = my_itoa_base(pixel, pixel_char, "01");
            //printf("befor  ->  %s\n", pixel_char);
            //printf("before the loop ->%d\n", is_finished);

            if (strlen(pixel_char) < coeff)
            {
                for (int k = 0, s = 0; k < coeff; k++, s++)
                {
                    if (s == 2)
                    {
                        z++;
                        s = 0;
                    }
                    pixel_char[k] = encode[z].bin[s];
                }
            }
            else if (encode[z + 1].bin == NULL && coeff > 2)
            {
                for (int k = 0; k < 2 - is_finished; k++, is_finished++)
                {
                    int calc = coeff - k;
                    pixel_char[strlen(pixel_char) - calc] =
                        encode[z].bin[is_finished];

                    //printf("is_finished -> %d\n", is_finished);
                }

            }
            else
            {
                for (int k = 0; k < coeff; k++, is_finished++)
                {
                    if (is_finished == 2)
                    {
                        z++;
                        is_finished = 0;
                    }
                    int calc = coeff - k;
                    pixel_char[strlen(pixel_char) - calc] =
                        encode[z].bin[is_finished];

                    //printf("is_finished -> %d\n", is_finished);
                }
            }
            if (is_finished == 2)
                is_finished = 0;
            //printf("after the loop ->%d\n", is_finished);

            //printf("after  ->  %s\n", pixel_char);
            Uint32 pixel_finish = my_atoi_base(pixel_char, "01");
            put_pixel(surface, i, j, pixel_finish);
            free(pixel_char);
            if (!is_finished)
                z++;
            //printf("\n");
        }
    }
    return surface;
}
