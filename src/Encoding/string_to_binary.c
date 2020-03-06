#include "Encoding/string_to_binary.h"

char *string_to_binary(char *string)
{
    if (!string)
        err(1, "Empty string given");

    char ascii[223] = {0};
    size_t len = strlen(string);
    for (size_t i = 0; i < strlen(string); i++)
    {
        if (ascii[string[i] - 32] == 0)
            ascii[string[i] - 32] = 1;
    }
    int i = 0;
    for (; i < 255; i++)
    {
        if (ascii[i] == 0)
            break;
    }
    char *key = calloc(len + 3, sizeof(char));
    key[0] = i + 32;
    string = strcat(string, key);
    key = strcat(key, string);
    free(string);

    len = strlen(key);
    char *my_bin = calloc(len * 8 + 1, sizeof(char));
    for (size_t i = 0; i < len; i++)
    {
        char my_char = key[i];
        for (int j = 7; j >= 0; j--)
        {
            if (my_char & (1 << j))
                strcat(my_bin, "1");
            else
                strcat(my_bin, "0");
        }
    }
    return my_bin;
}

struct encode *binary_to_struct(char *binary)
{
    int i = 0;
    int count = strlen(binary);
    struct encode *encode = calloc(strlen(binary) / 2, sizeof(struct encode));
    while (count != 0)
    {
        encode[i].bin = strndup(binary, 2);
        memmove(binary, binary + 2, strlen(binary) - 2);
        count -= 2;
        i++;
    }
    return encode;
}
