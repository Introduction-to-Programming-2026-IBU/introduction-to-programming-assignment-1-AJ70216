#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char*argv[])
{
    //check arguments
    if (argc !=4)
    {
        printf("Usage: ./volume input output factor\n");
        return 1;
    }

    //opem input file
    FILE*input=fopen(argv[1], "rb");
    if (input==NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    //open output file
    FILE*output=fopen(argv[2], "wb");
    if (output==NULL)
    {
        printf("Could not open output file.\n");
        return 1;
    }

    //convert factor to float
    float factor=atof(argv[3]);

    //copy header (44 bytes)
    BYTE header[44];
    fread(header, sizeof(BYTE), 44, input);
    fwrite(header, sizeof(BYTE), 44, output);

    //process samples
    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer=buffer*factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
