// You don't have to modify this file

#ifndef IMAGE_PROCESSING__ // header guard: to avoid the problem of multiple inclusion
#define IMAGE_PROCESSING__

/*
 * Negates the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void imgNegation(int **oData, int **rData, int height, int width);

/*
 * Converts the original image into a binary (black and white) image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void thresholding(int **oData, int **rData, int height, int width);

/*
 * Enhances the contrast of the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void histogramStretching(int **oData, int **rData, int height, int width);

/*
 * Applies a 3x3 median filter to the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void medianFilter(int **oData, int **rData, int height, int width);

/*
 * Detects edges in the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void edgeDetect(int **oData, int **rData, int height, int width);

#endif