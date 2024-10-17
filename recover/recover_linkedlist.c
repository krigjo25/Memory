/*******************************************************************************
    Title : Recover
    Description : Recover a corrupted JPEG file.
    Developed by : xCS50
******************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BYTESIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //  Initialize variables
    FILE *fw = NULL;
    FILE *f = NULL;

    int counter = 0;
    char filename[8];
    BYTE c[BYTESIZE];

    if (argc != 2)
    {
        //  Check the conditions for command line arguments
        printf("Usage : ./recover [path\\to\\file\\filename.raw]\n");
        return 1;
    }

    //  Open file
    f = fopen(argv[1], "r");

    if (!f)
    {
        printf("\"%s\" Does not exist, or simply is missplaced \n", argv[1]);
        return 1;
    }

    while (fread(c, BYTESIZE, 1, f) != 0)
    {
        //  Conditions for file format
        if (c[0] == 0xff && c[1] == 0xd8 && c[2] == 0xff && (c[3] == 0xe0 || c[3] == 0xe1))
        {
            //  Close file if found
            if (fw)
            {
                fclose(fw);
            }

            // Open a new file
            sprintf(filename, "%03d.jpg", counter);
            fw = fopen(filename, "w");

            // Counting upwards
            counter++;
        }

        if (fw)
        {
            fwrite(c, BYTESIZE, 1, fw);
        }
    }

    //  Close files
    if (fw)
    {
        fclose(fw);
    }

    fclose(f);

    return 0;
}
