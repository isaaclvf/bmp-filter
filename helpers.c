#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray;

    // Interate through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Gray filter algorithm
            gray = (image[i][j].rgbtBlue
                    + image[i][j].rgbtGreen
                    + image[i][j].rgbtRed) / 3;

            // Set pixel to gray
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalBlue, originalGreen;
    int sepiaRed, sepiaBlue, sepiaGreen;

    // Iterate through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Sepia algorithm
            sepiaRed = (int) (.393 * originalRed
                              + .769 * originalGreen
                              + .189 * originalBlue);

            sepiaGreen = (int) (.349 * originalRed
                                + .686 * originalGreen
                                + .168 * originalBlue);

            sepiaBlue = (int) (.272 * originalRed
                                + .534 * originalGreen
                                + .131 * originalBlue);

            // Avoid going over the maximum value for an 8-bit color
            if (sepiaRed > 255)
                sepiaRed = 255;

            if (sepiaGreen > 255)
                sepiaGreen = 255;

            if (sepiaBlue > 255)
                sepiaBlue = 255;

            // Set filtered values to the pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE tmp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int accumulatedRed = 0;
    int accumulatedGreen = 0;
    int accumulatedBlue = 0;

    int neighbours = 0;

    // Loop through every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            accumulatedRed = 0;
            accumulatedGreen = 0;
            accumulatedBlue = 0;
            neighbours = 0;

            // Loop through every neighbour pixel
            for (int ix = i - 1; ix <= i + 1; ix++)
            {
                if (ix >= 0 && ix <= height)
                {
                    for (int jx = j - 1; jx <= j + 1; jx++)
                    {
                        if(jx >= 0 && jx <= width)
                        {
                            accumulatedRed += image[ix][jx].rgbtRed;
                            accumulatedGreen += image[ix][jx].rgbtGreen;
                            accumulatedBlue += image[ix][jx].rgbtBlue;
                            neighbours++;
                        }
                    }
                }
            }

            image[i][j].rgbtRed = (int) accumulatedRed / neighbours;
            image[i][j].rgbtGreen = (int) accumulatedGreen / neighbours;
            image[i][j].rgbtBlue = (int) accumulatedBlue / neighbours;
        }
    }

    return;
}
