#include "binary_to_string.h"

int binary_to_string(char *binary)
{
    char letter = strtol(binary, 0, 2);
    if (letter < 0 || letter > 255)
        return 1;
    printf("%c", letter);
    return 0;
}
