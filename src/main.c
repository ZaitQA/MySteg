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

int encode(char *message, char *file, int encode_coeff)
{
    display(IMG_Load(file));
    char *binary = string_to_binary(message);
    struct encode *encode = binary_to_struct(binary);
    SDL_Surface *finish = encode_binary_in_wallpaper(IMG_Load(file), encode,
            encode_coeff);
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

int display_help()
{
    printf("\n                      How to use it :\n");
    printf("                      ---------------\n\n");
    printf("./steg to launch the tool\n\n");
    printf("few options are available to use it, those options are the following :\n\n");
    printf("-r [number] To decode an image with the number of bits you think it is encoded\n");
    printf("-e [number] To encode the message in the image with the number of bits\n");
    printf("-m [message] For the encoding to write your message\n");
    printf("-f [image] To choose the image you want to works on\n\n\n");
    printf("                        Examples :\n");
    printf("                        ----------\n\n");
    printf("If you want to see the differences between two images, you will need to do this :\n");
    printf("./steg -d test/'image name'.png test/'image name'.png\n\n");
    printf("If you want to encode some text into an image, you will need to do this :\n");
    printf("./steg -e 'number of bits' -f test/'image name'.png -m 'message to be encoded'\n\n");
    printf("If you want to decode some text from an image, you will need to do this :\n");
    printf("./steg -r 'number of bits' -f 'image name'.png\n\n\n");
    return 0;
}

int main(int argc, char *argv[])
{
    int opt = 0;
    char options[12] = "f0d0r0e0m0h0";
    char *file;
    char *message;
    int coeff = 2;
    while ((opt = getopt(argc, argv, "f:d:r:e:m:h")) != -1)
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
            coeff = atoi(optarg);
            break;
        case 'e':
            options[7] = '1';
            coeff = atoi(optarg);
            break;
        case 'm':
            options[9] = '1';
            message = strdup(optarg);
            break;
        case 'h':
            options[11] = '1';
            break;
        default:
            err(1, "Not like this");
            break;
        }
    }
    pretty_steg();
    if (!coeff)
    {
        printf("Need a coefficient > 0\n");
        return 1;
    }
    if (options[7] == '1')
        return encode(message, file, coeff);
    else if (options[5] == '1')
        return decode(coeff, file);
    else if (options[3] == '1')
        return difference(argv[2], argv[3]);
    else if (options[11] == '1')
        return display_help();
}
