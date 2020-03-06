# Steg
Steganography tool
How to use it :
./steg to launch the tool
few options are available to use it, those options are the following :
-r [number] To decode an image with the number of bits you think it is encoded
-e To encode the message in the image
-m [message] For the encoding to write your message
-f [image] To choose the image you want to works on

Example :
make (To be able to have an executable file)
./steg -e -f test/source.png -m "Salut les gars"
Nice the message is now encoded !
You have now three choices :
- Reencode a message in the same image
- See where the message has been encoded in your image
- Decode it to see if it's works

So you can do
./steg -r 2 -f text.png (To decode)
./steg -d source.png text.png

ENJOY !
