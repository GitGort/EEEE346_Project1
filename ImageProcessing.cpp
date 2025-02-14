#include "ImageProcessing.h"
#include <iostream> // to use cout and cin
#include <cmath> // to use sqrt()

using namespace std;

// This is a reference function that copies the image from oData to rData.
// See how arrays are utilized.
void copyImage(int **oData, int **rData, int height, int width) {
  for (int j=0; j<height; j++) {
    for (int k=0; k<width; k++) {
      rData[j][k] = oData[j][k];
    }
  }
}

void imgNegation(int **oData, int **rData, int height, int width) {
  // TODO: write your code
    output_pixel_value = 255 - original_pixel_value
}

void thresholding(int **oData, int **rData, int height, int width) {
  // TODO: write your code
}

void histogramStretching(int **oData, int **rData, int height, int width) {
  // TODO: write your code
}

void medianFilter(int **oData, int **rData, int height, int width) {
  // TODO: write your code
  // this loop moves the grid down through rows
  for (int row = 1; row < height - 1; row++)
  {
    // this loop moves the grid across the columns
    for (int column = 1; column < width - 1; column++)
    {
        // copy the 3x3 grid of values to a one dimensional array
        int group[9] =  {oData[row-1][column-1], oData[row-1][column], oData[row-1][column+1],
                        oData[row][column-1], oData[row][column], oData[row][column+1],
                        oData[row+1][column-1], oData[row+1][column], oData[row+1][column+1]};
        // sort the values in array 'group'
        // run through the array once for each element
        for (size_t run = 0; run < 8; run++)
        {
            // this loop pushes the largest element to the end of the array
            for (size_t element = 0; element < 8 - run; element++)
            if (group[element] > group[element + 1])
            {
                int temp = group[element];
                group[element] = group[element + 1];
                group[element + 1] = temp;
            }
        }
        // copy the median element to rdata
        rData[row][column] = group[4];
    }
  }
  //copy edge data to output
  //first loop for left/right sides
  for (int row = 0; row < height; row++)
  {
    rData[row][0] = oData[row][0];
    //remember to subtract one from size constants for proper indexing!
    rData[row][width-1] = oData[row][width-1];
  }
  
  //second loop for top/bottom
  for (int column = 0; column < width; column++)
    {
        rData[0][column] = oData[0][column];
        rData[height-1][column] = oData[height-1][column];
    }
    
}

void edgeDetect(int **oData, int **rData, int height, int width) {
  // X-direction filter
  int Fx[9] = {-1, 0, 1, 
               -2, 0, 2,
               -1, 0, 1};
  
  // Y-direction filter
  int Fy[9] = { 1,  2,  1, 
                0,  0,  0,
               -1, -2, -1};

  // TODO: write your code
  // this loop moves the grid down through rows
  for (int row = 1; row < height - 1; row++)
  {
    // this loop moves the grid across the columns
    for (int column = 1; column < width - 1; column++)
    {
        // copy the 3x3 grid of values to a one dimensional array
        int group[9] =  {oData[row-1][column-1], oData[row-1][column], oData[row-1][column+1],
                        oData[row][column-1], oData[row][column], oData[row][column+1],
                        oData[row+1][column-1], oData[row+1][column], oData[row+1][column+1]};
        // Create variables to store Gx and Gy
        int Gx = 0, Gy = 0;
        // multiply the adjacent values by the filters
        for (int element = 0; element < 9; element++)
        {
           Gx += group[element] * Fx[element];
           Gy += group[element] * Fy[element];
        }
        // calculate base of the root exp
        int base = (Gx * Gx) + (Gy * Gy);
        // calculate G
        int G = static_cast<int>(sqrt(base));
        // use min function to prevent >255 to be output
        rData[row][column] = min(255,G);
    }
  }
  //copy edge data to output
  //first loop for left/right sides
  for (int row = 0; row < height; row++)
  {
    rData[row][0] = oData[row][0];
    rData[row][width-1] = oData[row][width-1];
  }
  
  //second loop for top/bottom
  for (int column = 0; column < width; column++)
    {
        rData[0][column] = oData[0][column];
        rData[height-1][column] = oData[height-1][column];
    }
}
