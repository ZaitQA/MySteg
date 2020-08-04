# Steg
--------------------------------------------------------------------------------
Steganography tool

================================================================================
How to use it :
./steg to launch the tool


================================================================================
few options are available to use it, those options are the following :

-r [number] To decode an image with the number of bits you think it is encoded
-e [number] To encode the message in the image with the given coefficient
-m [message] For the encoding to write your message
-f [image] To choose the image you want to works on


================================================================================
Examples :

If you want to see the differences between two images, you will need to do this : 
./steg -d test/"the first image".png test/"the second image".png

If you want to encode some text into an image, you will need to do this :
./steg -e "number of bits per pixel you want to encode" -f test/name of the image".png -m "message you will need to encode"

If you want to decode some text from an image, you will need to do this :
./steg -r "number of bits you want to decode per pixel" -f "name of the image".png
--------------------------------------------------------------------------------
