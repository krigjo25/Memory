
// Importing responsories
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./license infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Initializing a pointer as an array
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    //  Initializing a c(ounter)
    int c = 0;

    // Looping through the file
    while (fread(buffer, 1, 7, infile) == 7)
    {

        buffer[6] = '\0';

        // Save plate number in array
        plates[c] = buffer;
        printf("%s\n", plates[c]);
        c++;
    }
}
