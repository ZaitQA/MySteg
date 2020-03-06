#include <getopt.h>

#include "Encoding/string_to_binary.h"
#include "Display/display.h"
#include "Encoding/Treatment_encoding.h"
#include "Decoding/Treatment_decoding.h"
#include "Display/save.h"
#include "Difference/Treatment_difference.h"

void pretty_steg(void)
{
    printf("                                                               \n");
    printf("         ______     _________   _________     _______          \n");
    printf("        / ____ \\   (___   ___) (  _______)   / ____  \\       \n");
    printf("       / /    \\ \\      \\ /      \\ \\         / /     \\_)  \n");
    printf("      ( )      (_)     | |      | |        | |                 \n");
    printf("       \\ \\____         | |      | |____    | |               \n");
    printf("        \\____ \\        | |      |  ____)   | |    _____      \n");
    printf("      _      \\ \\       | |      | |        | |   (___  )     \n");
    printf("     ( )      ( )      | |      | |        | |      | |        \n");
    printf("      \\ \\____/ /       | |      / /______   \\ \\_____/ /    \n");
    printf("       \\______/        (_)     (_________)   \\_______/       \n");
    printf("______________________________________________________________\n\n");
    printf("        Steganography tool to exploit images at 100\%\n");
    printf("                      Version 1.0                              \n");
    printf("                         @zait                                 \n");
    printf("______________________________________________________________\n\n");
}

int encode(char *message, char *file)
{
    display(IMG_Load(file));
    char *binary = string_to_binary(message);
    struct encode *encode = binary_to_struct(binary);
    SDL_Surface *finish = encode_binary_in_wallpaper(IMG_Load(file), encode);
    display(finish);
    save(finish);
    return 0;
}

int decode(int decode_coeff, char *file)
{
    printf("Message :\n\n");
    decode_wallpaper_in_string(IMG_Load(file), decode_coeff);
    return 0;
}

int difference(char *argv, char *argv2)
{
   SDL_Surface *finish = show_difference(IMG_Load(argv), IMG_Load(argv2));
   display(finish);
   return 0;
}

int main(int argc, char *argv[])
{
    int opt = 0;
    char options[10] = "f0d0r0e0m0";
    char *file;
    char *message;
    int decode_coeff;
    while ((opt = getopt(argc, argv, "f:d:r:em:")) != -1)
    {
        switch(opt)
        {
        case 'f':
            options[1] = '1';
            file = strdup(optarg);
        case 'd':
            options[3] = '1';
            break;
        case 'r':
            options[5] = '1';
            decode_coeff = atoi(optarg);
            break;
        case 'e':
            options[7] = '1';
            break;
        case 'm':
            options[9] = '1';
            message = strdup(optarg);
            break;
        default:
            err(1, "Not like this");
            break;
        }
    }
    pretty_steg();
    if (options[7] == '1')
        return encode(message, file);
    else if (options[5] == '1')
        return decode(decode_coeff, file);
    else if (options[3] == '1')
        return difference(argv[2], argv[3]);
}
