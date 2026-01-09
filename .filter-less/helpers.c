#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //  TODO: this is where we hadle the pixels
            // take the red green and blue of the current pixel
            // add them together and divde by 3 qand then set all three to that value
            float average =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            average = round(average);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                        .189 * image[i][j].rgbtBlue;

            float green = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                          .168 * image[i][j].rgbtBlue;

            float blue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                         .131 * image[i][j].rgbtBlue;

            red = round(red);
            green = round(green);
            blue = round(blue);

            image[i][j].rgbtRed = ((red > 255) ? 255 : (BYTE) red);
            image[i][j].rgbtGreen = ((green > 255) ? 255 : (BYTE) green);
            image[i][j].rgbtBlue = ((blue > 255) ? 255 : (BYTE) blue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // get our last rgb value
        RGBTRIPLE rgb = image[i][width - 1];

        for (int j = 0; j < (width / 2); j++)
        {
            // for each rgb in loop we want to swap it with the one at the last
            // first inteartion = rgb1 = (width - 1 - j)
            // set rgb to j

            // set the last value to the current value
            image[i][width - 1 - j] = image[i][j];
            // set the current value to the last value
            image[i][j] = rgb;
            // chnge the last value
            rgb = image[i][width - 2 - j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    double red, green, blue;
    int count;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // read from copy to write to image
    for (int i = 0; i < height; i++)
    { // for each row (image[i][])

        for (int j = 0; j < width; j++)
        { // for each cell in that row

            count = 0;
            red = 0;
            green = 0;
            blue = 0;

            for (int oi = -1; oi < 2; oi++)
            { // row offset

                for (int oj = -1; oj < 2; oj++)
                { // col offset

                    // calculate the ofset for rows and columns
                    int rowOffset = i + oi;
                    int colOffset = j + oj;

                    // check if they are in bounds of the image
                    if (rowOffset >= 0 && rowOffset < height && colOffset >= 0 && colOffset < width)
                    { // read the values of the copy using the offset and get the sum
                        red += copy[rowOffset][colOffset].rgbtRed;
                        green += copy[rowOffset][colOffset].rgbtGreen;
                        blue += copy[rowOffset][colOffset].rgbtBlue;

                        // count each sum
                        count++;
                    }
                }
            } // gotten the sum of all the rgb values
            // now to divide by counter

            red = round(red / count);
            green = round(green / count);
            blue = round(blue / count);

            // write the updated rgb values to he main image
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

