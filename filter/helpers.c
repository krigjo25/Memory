/*******************************************************************************
    Title : Filter - less
    Description :   Various of filters used to costumize photos

    Base by : CS50, Problem set 04
    Developed by : @krigjo25
    Date Started : DD/NN/ YYYYY
    Date Submited : Tuesday, August 1, 2023 7:35 AM CEST
    Date re-Submited : N/A

******************************************************************************/

#include "helpers.h"
#include "math.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    //  for each row
    for (int i = 0; i < height; i++)
    {
        //  for each column
        for (int j = 0; j < width; j++)
        {

            //  Initialize a Temporary variable
            float temp;

            //  Fetch the average color
            temp = image[i][j].rgbtRed;
            temp += image[i][j].rgbtGreen;
            temp += image[i][j].rgbtBlue;
            temp = round(temp / 3.0);

            //  Assign the value to RGB
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtGreen = temp;
            image[i][j].rgbtBlue = temp;

            //  Ensure rgb is greater than 255
            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }

            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }

            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //  for each row
    for (int i = 0; i < height; i++)
    {
        //  for each column
        for (int j = 0; j < width; j++)
        {

            //  Initialize a Temporary variable
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                             .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                               .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                              .131 * image[i][j].rgbtBlue;

            //  Calulating sepia Colour
            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //  Assign RGB
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

    //  For each row
    for (int i = 0; i < height; i++)
    {

        //  For each column
        for (int j = 0; j < width - j - 1; j++)
        {

            //  Initializing temp variables for each color (RGB)
            RGBTRIPLE tmp;
            tmp.rgbtRed = round(image[i][width - j - 1].rgbtRed);
            tmp.rgbtGreen = round(image[i][width - j - 1].rgbtGreen);
            tmp.rgbtBlue = round(image[i][width - j - 1].rgbtBlue);

            //  Assigning new values left to right
            image[i][width - j - 1].rgbtRed = round(image[i][j].rgbtRed);
            image[i][j].rgbtRed = tmp.rgbtRed;

            image[i][width - j - 1].rgbtGreen = round(image[i][j].rgbtGreen);
            image[i][j].rgbtGreen = tmp.rgbtGreen;

            image[i][width - j - 1].rgbtBlue = round(image[i][j].rgbtBlue);
            image[i][j].rgbtBlue = tmp.rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Initialize variables
    RGBTRIPLE RGB[height][width];

    //  Copies RGB values
    for (int y = 0; y < height; y++)
    {

        for (int x = 0; x < width; x++)
        {
            //  Copy RGB Values
            RGB[y][x].rgbtRed = image[y][x].rgbtRed;
            RGB[y][x].rgbtGreen = image[y][x].rgbtGreen;
            RGB[y][x].rgbtBlue = image[y][x].rgbtBlue;
        }
    }

    // Corners
    for (int y = 0; y <= height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int counter = 0;
            int average_r = 0;
            int average_g = 0;
            int average_b = 0;

            // Checking Corners n / 4
            if (y == 0 || y == height)
            {
                // Top left
                if (y == 0 && x == 0)
                {
                    for (int i = 0; i < y + 1; i++)
                    {
                        for (int j = 0; j < x + 1; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }

                // top right
                else if (y == 0 && x == width)
                {
                    for (int i = 0; i < y + 1; i++)
                    {
                        for (int j = width - 1; j < x; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }

                // Bottom- left
                else if (y == height && x == 0)
                {
                    for (int i = height - 1; i < y; i++)
                    {

                        for (int j = 0; j < x + 1; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }
                // bottom / right
                else if (y == height && x == width)
                {
                    for (int i = height - 1; i < y; i++)
                    {

                        for (int j = width - 1; j < x; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }

            }

            //  Checking the edges of the image
            else if (y < height)
            {
                if (y == 0 || y == height - 1)
                {
                    // Top edges
                    for (int i = 0; i < y + 1; i++)
                    {
                        for (int j = 0; j < x + 2; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }
                if (x > 0 && x < width)
                {
                    // Top edges
                    for (int i = 0; i < y + 1; i++)
                    {
                        for (int j = 0; j < x + 2; j++)
                        {
                            average_r += RGB[i][j].rgbtRed;
                            average_g += RGB[i][j].rgbtGreen;
                            average_b += RGB[i][j].rgbtBlue;

                            counter++;
                        }
                        counter++;
                    }
                }
                if (x == 0 && x == width)
                {
                }
                else
                {
                }
            }
            else
            {
            }

            //  Calculating average for each pixel
            average_r = round(average_r) / counter;
            average_g = round(average_g) / counter;
            average_b = round(average_b) / counter;

            image[y][x].rgbtRed = average_r;
            image[y][x].rgbtGreen = average_g;
            image[y][x].rgbtBlue = average_b;
        }
    }
    return;
}
