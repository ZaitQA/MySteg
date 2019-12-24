#include "Tools.h"

Uint8* pixelref(SDL_Surface *surface, unsigned x, unsigned y)
{
    int bpp = surface -> format -> BytesPerPixel;
    return (Uint8*)surface -> pixels + y * surface -> pitch + x * bpp;
}

Uint32 getpixel(SDL_Surface *surface, unsigned x, unsigned y)
{
    Uint8 *p = pixelref(surface, x, y);
    return p[0] << 16 | p[1] << 8 | p[2];
}

void put_pixel(SDL_Surface *surface, unsigned x, unsigned y, Uint32 pixel)
{
    Uint8 *p = pixelref(surface, x, y);
    p[0] = (pixel >> 16);
    p[1] = (pixel >> 8);
    p[2] = pixel;
}

int length(const char *str)
{
    int result = 0;
    while (str[result] != '\0')
    {
        result += 1;
    }
    return result;
}

int number_digits(int n, int length)
{
    if (n == 0)
        return 1;
    int result = 0;
    while (n != 0)
    {
        n /= length;
        result += 1;
    }
    return result;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int number = 0;
    int lengthnumber = 0;
    int len = length(base);
    int diff = 0;
    if (n == 0)
    {
        s[0] = 0;
        s[1] = '\0';
    }
    if (n < 0)
    {
        n = -n;
        s[0] = '-';
        diff = 1;
    }
    lengthnumber = number_digits(n, len);
    for (int i = lengthnumber + diff - 1; i >= 0 + diff; i--)
    {
        number = n % len;
        n = n / len;
        s[i] = base[number];
    }
    s[lengthnumber + diff] = '\0';
    return s;
}

int search(char i, const char *base)
{
    int index = 0;
    while (base[index] != '\0')
    {
        if (base[index] == i)
        {
            return index;
        }
        index += 1;
    }
    return -1;
}

int my_atoi_base(const char *str, const char *base)
{
    int space = 1;
    int sign = 0;
    int len = length(base);
    int result = 0;
    for (unsigned i = 0; str[i] != '\0'; i++)
    {
        int index = search(str[i], base);
        if ((str[i] == ' ' && space != 1) || (str[i] == '+' && space != 1)
                || (str[i] == '-' && space != 1))
            return 0;
        else if (space == 1 && str[i] == '-')
        {
            sign = -1;
            space += 1;
        }
        else if (space == 1 && str[i] == '+')
        {
            sign = 1;
            space += 1;
        }
        else if (index != -1 && space == 1)
        {
            sign = 1;
            space += 1;
            i--;
        }
        else if (sign != 0)
        {
            if (index != -1)
            {
                result = result * len + index;
            }
            else
                return 0;
        }
    }
    return result * sign;
}

