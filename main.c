#include "Encoding/string_to_binary.h"
#include "Display/display.h"
#include "Encoding/Treatment_encoding.h"
#include "Decoding/Treatment_decoding.h"
#include "Display/save.h"
#include "Difference/Treatment_difference.h"
#include <getopt.h>

void pretty_steg(void)
{
    printf("_______________________________________________________________");
    printf("\n\n");
   
    printf("         ########  ###########  #########   ########\n");
    printf("       #####  ####    #####     ####       ###   ####\n");
    printf("       ###       ##    ###      ##        ###      ###\n");
    printf("         ####          ###      ###      ###\n");
    printf("           #####       ###      ######   ###     #####\n");
    printf("             ####      ###      ###      ###        ###\n");
    printf("      ##       ###     ###      ##        ###       ###\n");
    printf("       ####  #####     ###      ####       ###   ####\n");
    printf("         #######       ###      #########   ########\n\n\n");
    printf("        Steganography tool to exploit images at 100\%\n");
    printf("                      Version 1.0\n");
    printf("                         @zait\n");
    printf("_______________________________________________________________");
    printf("\n\n");
}

int encode(char *message, char *file)
{
    display(IMG_Load(file));
    printf("Encoding starting now :              0\%\n");
    sleep(1);
    char *binary = string_to_binary(message);
    printf("Message in binary form :             20\%\n");
    sleep(1);
    struct encode *encode = binary_to_struct(binary);
    printf("Struct created :                     50\%\n");
    sleep(1);
    SDL_Surface *finish = encode_binary_in_wallpaper(IMG_Load(file), encode);
    printf("Message is now in the given image :  80\%\n");
    sleep(1);
    display(finish);
    printf("Encoding now terminated :            100\%\n\n");
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
