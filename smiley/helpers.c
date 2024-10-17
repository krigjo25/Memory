#include "helpers.h"

/*******************************************************************
 *  Title       : Smiley
 *  Description : Implements a CS program to create a image
 *  Base By     :  xCS50
 *  Created by  : @krigjo25
 ******************************************************************/
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // When working with 2D arrays, use for loop ( it always work)
    // Change all black pixels to a color of your choosing

    // for each row
    for (int i = 0; i < height; i++)
    {
        // for each column
        for (int j = 0; j < width; j++)
        {
            if (i % 2)
            {
                if (j % 2)
                {
                    // RGB values
                    image[i][j].rgbtRed = 102;
                    image[i][j].rgbtGreen = 74;
                    image[i][j].rgbtBlue = 140;
                }
            }
        }
    }
}
