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
    if (chunk == NULL)
    {
        perror("Buffer Memory allocation failed");
        fclose(card);
        return 2;
    }

    // read each chunk
    int count = 0;
    while(fread(chunk, 1, CHUNK_SIZE, card) == CHUNK_SIZE)
    {
        // if chunk is header then open file
        if (chunk[0] == 255 &&
            chunk[1] == 216 &&
            chunk[2] == 255 &&
            (chunk[3] & 240) == 224)
        {
            // get image file name
            char filename[8];
            sprintf(filename, "%03i.jpg", count);

            // open image
            FILE *image = fopen(filename, "wb");
            if (image == NULL)
            {
                perror("Failed to create image");
                fclose(card);
                return 3;
            }

            // write to image
            if (fwrite(chunk, 1, CHUNK_SIZE, image) != CHUNK_SIZE)
            {
                perror("Failed to write to image");
                fclose(card);
                fclose(image);
                return 4;
            }

            count++;
        }


    }


    // if header then then
        // open a new file
        // write to it
        //
    // if not keep looping until end of file
    // close everything
    fclose(card);
    fclose(image);
    return 0;
}
