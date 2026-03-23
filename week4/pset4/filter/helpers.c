#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int average=(image[i][j].rgbtBlue+
                image[i][j].rgbtGreen+
                image[i][j].rgbtRed)/3.0+0.5;
            image[i][j].rgbtRed=average;
            image[i][j].rgbtGreen=average;
            image[i][j].rgbtBlue=average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int originalRed=image[i][j].rgbtRed;
            int originalGreen=image[i][j].rgbtGreen;
            int originalBlue=image[i][j].rgbtBlue;

            int sepiaRed=round(0.393*originalRed+0.769*originalGreen+0.189*originalBlue);
            int sepiaGreen=round(0.349*originalRed+0.686*originalGreen+0.168*originalBlue);
            int sepiaBlue=round(0.272*originalRed+0.534*originalGreen+0.131*originalBlue);

            if (sepiaRed>255)
            {
                sepiaRed=255;
            }
            if (sepiaGreen>255)
            {
                sepiaGreen=255;
            }
            if (sepiaBlue>255)
            {
                sepiaBlue=255;
            }

            image[i][j].rgbtRed=sepiaRed;
            image[i][j].rgbtGreen=sepiaGreen;
            image[i][j].rgbtBlue=sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width/2; j++)
        {
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-1-j];
            image[i][width-1-j]=temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    //copy original image
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            copy[i][j]=image[i][j];
        }
    }

    //blur
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            int totalRed=0;
            int totalGreen=0;
            int totalBlue=0;
            int count=0;

            for (int di=-1; di<=1; di++)
            {
                for (int dj=-1; dj<=1; dj++)
                {
                    int ni=i+di;
                    int nj=j+dj;

                    if (ni>=0&&ni<height&&nj>=0&&nj<width)
                    {
                        totalRed+=copy[ni][nj].rgbtRed;
                        totalGreen+=copy[ni][nj].rgbtGreen;
                        totalBlue+=copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed=round((float)totalRed/count);
            image[i][j].rgbtGreen=round((float)totalGreen/count);
            image[i][j].rgbtBlue=round((float)totalBlue/count);
        }
    }
}
