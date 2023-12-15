#include <stdio.h>
#include <stdlib.h>

// Function to check if the buffer contains a JPEG header
int is_start_of_new_jpeg(unsigned char buffer[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open memory card file
    char *infile = argv[1];
    FILE *inputFile = fopen(infile, "r");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];
    FILE *outputFile = NULL;
    int jpgCount = 0;
    char filename[8]; // Filenames are 000.jpg to 049.jpg, etc.

    // Repeat until end of card
    while (fread(buffer, sizeof(buffer), 1, inputFile))
    {
        // Check for the start of a new JPEG
        if (is_start_of_new_jpeg(buffer))
        {
            // If not first JPEG, close previous file
            if (outputFile != NULL)
            {
                fclose(outputFile);
            }

            // Create a new filename
            sprintf(filename, "%03i.jpg", jpgCount++);

            // Open a new image file
            outputFile = fopen(filename, "w");
            if (outputFile == NULL)
            {
                fprintf(stderr, "Could not create file %s.\n", filename);
                fclose(inputFile);
                return 3;
            }
        }

        // If already found JPEG, keep writing to it
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputFile);
        }
    }

    // Close any remaining files
    if (outputFile != NULL)
    {
        fclose(outputFile);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}

// Function to check if the buffer contains a JPEG header
int is_start_of_new_jpeg(unsigned char buffer[])
{
    return buffer[0] == 0xff &&
           buffer[1] == 0xd8 &&
           buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}
