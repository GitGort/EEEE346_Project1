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
  for (int row = 1; row < width; row++)
  {
    // this loop moves the grid across the columns
    for (int column = 1; column < height; column++)
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
        rData[row][column] = group[4];
    }
  }
  //copy edge data to output
  //first loop for left/right sides
  for (size_t row = 0; row <= height; row++)
  {
    rData[row][0] = oData[row][0];
    rData[row][width] = oData[row][width];
  }
  
  //second loop for top/bottom
  for (size_t column = 1; column < height; column++)
    {
        rData[0][column] = oData[0][column];
        rData[height][column] = oData[height][column];
    }
    
}

void edgeDetect(int **oData, int **rData, int height, int width) {
  // X-direction filter
  int Fx[3][3] = {{-1, 0, 1}, 
                  {-2, 0, 2},
                  {-1, 0, 1}};
  
  // Y-direction filter
  int Fy[3][3] = {{ 1,  2,  1}, 
                  { 0,  0,  0},
                  {-1, -2, -1}};

  // TODO: write your code
}