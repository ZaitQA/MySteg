#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char bit_reverse(char c)
{
    if (c == '0')
        return '1';
    return '0';
}

char *create_mask(char *bits, char *message, size_t len)
{
    char *mask = calloc(sizeof(char), len + 2);
    for (size_t i = 0; i < len; i++)
    {
        if (message[i] == '0')
            mask[i] = bits[i];
        if (message[i] == '1')
            mask[i] = bit_reverse(bits[i]);
    }
    return mask;
}

/*int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;
    char *s = create_mask(argv[1], argv[2], strlen(argv[1]));
    printf("%s\n", s);
    free(s);
    return 0;
}*/
