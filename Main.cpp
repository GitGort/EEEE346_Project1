// You don't have to modify this file

#include "ImageProcessing.h"
#include "PGM.h"

using namespace std;

const int MAX_OPERATION_NUMBER = 5;
const int NEGATE_OPERATION     = 0;
const int THRESHOLD_OPERATION  = 1;
const int STRETCHING_OPERATION = 2;
const int MEDIAN_OPERATION     = 3;
const int EDGEDETECT_OPERATION = 4;

// Memory for original image
int **original;

// Memory for modified image
int **modified;

// Height of the original
int height;

// Width of the original
int width;

// Grab a file name
string getFileName(string prompt);

// Cout menu options
void printMenu();

// Allocate dynamic memory
void allocateMemory(int height, int width);

// Check continue
bool checkContinue();

// Read an image
bool readFile(string fileName);

// Perform appropriate operation, call function pointer
void performOperation(unsigned int op);

// Write a resulting image
bool saveFile(string modifiedName);

// Deallocate dynamic memory and close filewrite
void cleanUp();

int main() { //{{{
  unsigned int op;
  string originalName;
  string modifiedName;

  do {
    // Prompt and return original file name
    originalName = getFileName("Enter Original File Name");

    // Read in the file
    if (readFile(originalName)) {
      // Prompt for operation
      printMenu();

      // Grab operation
      cin >> op;

      if (op <= MAX_OPERATION_NUMBER) {
        // Prompt and return save file name
        modifiedName = getFileName("Enter Save File Name");

        // Perform the operation
        performOperation(op);

        // Save the file after the operation
        if (!saveFile(modifiedName)) {
          cout << "Failed to write out file";
        }

        // Clean up memory
        cleanUp();
      } else {
        cout << "Invalid operation specified!\n";
      }
    } else {
      cout << "Bad File " << original << endl;
    }

    // Prompt to continue, exit if no
  } while (checkContinue());

  return 0;
} //}}}

string getFileName(string prompt) { //{{{
  string fileName;
  cout << prompt << ": ";
  cin >> fileName;

  return fileName;
} //}}}

void printMenu() { //{{{
  cout << "File Successfully Opened\n";
  cout << "Select Operation:\n";
  cout << "\t(" << NEGATE_OPERATION << ") Negation \n";
  cout << "\t(" << THRESHOLD_OPERATION << ") Thresholding \n";
  cout << "\t(" << STRETCHING_OPERATION << ") Histogram Stretching \n";
  cout << "\t(" << MEDIAN_OPERATION << ") Median Filter \n";
  cout << "\t(" << EDGEDETECT_OPERATION << ") Edge Detection \n";
  cout << "Enter Selection: ";
} //}}}

void allocateMemory(int height, int width) { //{{{
  original = new int* [height];
  modified = new int* [height];
  for (int i=0; i<height; i++) {
    original[i] = new int [width];
    modified[i] = new int [width];
  }
} //}}}

bool readFile(string fileName) { //{{{
  if (openPGM(fileName)) {
    // Store image dimensions
    width = getPGMWidth();
    height = getPGMHeight();

    // Allocate memory before reading in the file
    allocateMemory(height, width);

    // Read image into memory
    getPGMData(original);

    return true;
  } else {
    return false;
  }
} //}}}

bool checkContinue() { //{{{
  char check;
  cout << "Perform another operation [y/n]? ";
  cin >> check;
  cout << endl << endl;
  return ((check == 'y') || (check == 'Y'));
} //}}}

void performOperation(unsigned int op) { //{{{
  cout << "Performing Operation..." << endl;

  switch (op) {
  	case NEGATE_OPERATION:
  	  imgNegation(original, modified, height, width);
  	  break;
  	case THRESHOLD_OPERATION:
  	  thresholding(original, modified, height, width);
  	  break;
  	case STRETCHING_OPERATION:
  	  histogramStretching(original, modified, height, width);
  	  break;
  	case MEDIAN_OPERATION:
  	  medianFilter(original, modified, height, width);
  	  break;
  	case EDGEDETECT_OPERATION:
  	  edgeDetect(original, modified, height, width);
  	  break;
  	default:
  	  break;
  }
} //}}}

bool saveFile(string modifiedName) { //{{{
  cout << "Writing out the File...\n";
  return writePGM(modifiedName, modified);
} //}}}

void cleanUp() { //{{{
  cout << "Cleaning up now!\n";
  // Clean-up dynamic allocated memory
  for (int i=0; i<height; i++) {
    delete [] original[i];
    delete [] modified[i];
  }
  delete [] original;
  delete [] modified;

  // Close the opened image
  closePGM();
  cout << "Clean-up finished.\n";
} //}}}