#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 512

int main(int argc, char *argv[])
{
    // get command line argumants
    if (argc != 2)
    {
        printf("Usage: ./recover car_name.raw\n");
        return 1;
    }

    // open the card
    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // loop through the contents of the card in 512 size chunk
    uint8_t chunk[CHUNK_SIZE];

    // read each chunk
    int count = 0;

    // init image pointer outside loop and only asign image during loop
    FILE *image = NULL;

    // starts reading chunk
    while (fread(chunk, 1, CHUNK_SIZE, card) == CHUNK_SIZE)
    {
        // if chunk is header then open file
        if (chunk[0] == 0xff && chunk[1] == 0xd8 && chunk[2] == 0xff && (chunk[3] & 0xf0) == 0xe0)
        {

            // if chunk is a header, before we open a new image to write to check if image is null
            // if not then close it
            if (image != NULL)
            {
                fclose(image);
            }

            // get image file name
            char filename[8];
            sprintf(filename, "%03i.jpg", count);

            // open image
            image = fopen(filename, "wb"); // need to close image after we found a new image
            if (image == NULL)
            { // if fialed close card
                perror("Failed to create image");
                fclose(card);
                return 2;
            }

            // write to image
            if (fwrite(chunk, 1, CHUNK_SIZE, image) != CHUNK_SIZE)
            { // if fialed close card and image
                perror("Failed to write to image");
                fclose(image);
                fclose(card);
                return 2;
            }

            count++;
        }
        else if (image != NULL)
        { // write to image
            if (fwrite(chunk, 1, CHUNK_SIZE, image) != CHUNK_SIZE)
            { // if fialed close card andimage
                perror("Failed to write to image");
                fclose(image);
                fclose(card);
                return 2;
            }
        }
    }

    // close image at the end of writing
    if (image != NULL)
    {
        fclose(image);
    }

    // close everything
    fclose(card);
    return 0;
}

