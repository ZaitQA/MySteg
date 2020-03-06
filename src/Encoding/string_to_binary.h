#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>

struct encode
{
    char *bin;
};

char *string_to_binary(char *string);
struct encode *binary_to_struct(char *binary);
