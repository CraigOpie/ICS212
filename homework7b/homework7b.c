/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       homework7b
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR      Ravi Narayan
//
//  DATE:           Mar 27, 2020
//
//  FILE:           homework7b.c
//
//  DESCRIPTION:    This file modifies color tables for gif files.
//
******************************************************************************/

#include <stdio.h>
#include <string.h>

void printinfor(unsigned char []);
void modify(unsigned char []);
int readfile(unsigned char [], int*, char []);
int writefile(unsigned char [], int, char []);

/******************************************************************************
//
//  FUNCTION NAME:  main
//
//  DESCRIPTION:    Main function modifies color tables for gif files.
//
//  PARAMETERS:     argv[1] - filename to read.
//                  argv[2] - filename to write.
//
//  RETURN VALUES:  0 : Success.
//
******************************************************************************/

int main(int argc, char* argv[])
{
    unsigned char data[4000];
    int data_size = 0;
    int success = 0;
    char infile[100];
    char outfile[100];

    if (argc < 2)
    {
        strcpy(infile, "image1.gif");
        strcpy(outfile, "result1.gif");
        printf("Default filenames were used: 'image1.gif' & 'result1.gif'\n");
    }
    else
    {
        strcpy(infile, argv[1]);
        strcpy(outfile, argv[2]);
    }
    

    success = readfile(data, &data_size, infile);
    if (success != 0)
    {
        printf("ERROR: Cannot read from file.  Please verify filename is ");
        printf("correct.\n");
    }
    else
    {
        printinfor(data);
        modify(data);
        printinfor(data);
        success = writefile(data, data_size, outfile);
        if (success != 0)
        {
            printf("ERROR: Cannot write from file.  Please verify you have ");
            printf("correct permissions.\n");
        }
    }

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME:  printinfor
//
//  DESCRIPTION:    printinfor function informs the user about the gif file's
//                  width, height, and color.
//
//  PARAMETERS:     data[] - array of binary data.
//
//  RETURN VALUES:  None.
//
******************************************************************************/

void printinfor(unsigned char data[])
{
    unsigned int width;
    unsigned int height;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;

    width = (data[7] << 8) + (data[6]);
    height = (data[9] << 8) + (data[8]);
    red = (data[15] << 16) + (data[14] << 8) + (data[13]);
    green = (data[18] << 16) + (data[17] << 8) + (data[16]);
    blue = (data[21] << 16) + (data[20] << 8) + (data[19]);
    alpha = (data[24] << 16) + (data[23] << 8) + (data[22]);


    printf("Width:  %d\n", width);
    printf("Height: %d\n", height);
    printf("Color 1, 2, 3, and 4:\n");
    printf("R value: %06x\n", red);
    printf("G value: %06x\n", green);
    printf("B value: %06x\n", blue);
    printf("A value: %06x\n\n", alpha);
}

/******************************************************************************
//
//  FUNCTION NAME:  modify
//
//  DESCRIPTION:    modify function modifies the gif color pallette.
//
//  PARAMETERS:     data[] - array of binary data.
//
//  RETURN VALUES:  None.
//
******************************************************************************/

void modify(unsigned char data[])
{
    int i;
    int j;
    int large;

    for (j = 13; j < 22;)
    {
        large = 1;
        for (i = j; i < (j + 3); i++)
        {
            if ((data[i] & 0x80) != 0x80)
            {
                large = 0;
            }
        }
        if (large)
        {
            for (i = j; i < (j + 3); i++)
            {
                data[i] = ((data[i] << 2) & 0xff);
            }
        }
        else
        {
            for (i = j; i < (j + 3); i++)
            {
                if (i == j)
                {
                    data[i] = (data[i] & 0xde);
                }
                else if (i == (j + 1))
                {
                    data[i] = ((data[i] & 0x0f) << 4 | (data[i] & 0xf0) >> 4);
                }
                else
                {
                    data[i] = ((data[i] & 0x77) | ((data[i] & 0x88) ^ 0x88));
                }
            }
        }
        j = j + 3;
    }
}

/******************************************************************************
//
//  FUNCTION NAME:  readfile
//
//  DESCRIPTION:    readfile function reads the binary file into the array.
//
//  PARAMETERS:     data[]     - array of binary data.
//                  *data_size - location to store the number of bytes in the
//                               binary file being read.
//                  filename[] - filename of the file to be read.
//
//  RETURN VALUES:  0 : success.
//                  -1: failure.
//
******************************************************************************/

int readfile(unsigned char data[], int * data_size, char filename[])
{
    int success = 0;

    FILE * infile;
    infile = fopen(filename, "rb");

    if (infile == NULL)
    {
        success = -1;
    }
    else
    {
        while (fgetc(infile) != EOF)
        {
            *data_size += 1;
        }
        fclose(infile);

        infile = fopen(filename, "rb");
        fread(data, *data_size, 1, infile);
        fclose(infile);
    }

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME:  writefile
//
//  DESCRIPTION:    writefile function writes the array into a binary file.
//
//  PARAMETERS:     data[]     - array of binary data.
//                  data_size  - number of bytes in the binary file being
//                               written.
//                  filename[] - filename of the file to be written.
//
//  RETURN VALUES:  0 : success.
//                  -1: failure.
//
******************************************************************************/

int writefile(unsigned char data[], int data_size, char filename[])
{
    int success = 0;
    
    FILE * outfile;
    outfile = fopen(filename, "wb");

    if (outfile == NULL)
    {
        success = -1;
    }
    else
    {
        fwrite(data, data_size, 1, outfile);
        fclose(outfile);
    }

    return success;
}
