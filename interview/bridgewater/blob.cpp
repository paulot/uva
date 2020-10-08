#include <iostream>
#include <fstream>
#define len 10

using namespace std;

// The input and the set of already visited nodes
bool occupied[len][len], visited[len][len];

// The data to return back to the user
int numberOfReads = 0, topBound = -1, leftBound = -1, botBound = -1, rightBound = -1;


// Returns the value of a given cell. 
//
// This helper function is used in order to ensure that no cell is visited twice and to ensure
// that every read from the input data is accounted for.
//
// Input:
//  int i: Row number of the point to check.
//  int j: Column number of the point to check.
//
// Returns:
//  bool: Is the given cell occupied or not?
bool readCell(int i, int j) {
  visited[i][j] = true;
  numberOfReads++;
  return occupied[i][j];
}

// Executes a flood fill on the input, while updating the boundaries.
//
// The idea is to check all sides of a given point, without re-visiting points that have already been
// visited. This should only get executed on points set to '1'.
//
// Input:
//  int i: Row number of the point to check.
//  int j: Column number of the point to check.
void floodFill(int i, int j) {
  // Update boundaries.
  botBound = max(botBound, i);
  rightBound = max(rightBound, j);
  leftBound = min(leftBound, j);

  // Visit neighbor above
  if (i > 0 and not visited[i - 1][j] and readCell(i - 1, j)) {
    floodFill(i - 1, j);
  }

  // Visit neighbor below
  if (i + 1 < len and not visited[i + 1][j] and readCell(i + 1, j)) {
    floodFill(i + 1, j);
  }

  // Visit left neighbor
  if (j > 0 and not visited[i][j - 1] and readCell(i, j - 1)) {
    floodFill(i, j - 1);
  }

  // Visit right neighbor
  if (j + 1 < len and not visited[i][j + 1] and readCell(i, j + 1)) {
    floodFill(i, j + 1);
  }
}

int main(int argc, char *argv[]) {
  // Handle command line arguments
  if (argc != 2) {
    cout << "Usage: ./blob <filename>" << endl;
    return 1;
  }

  // Open file and check for existence
  char *filename = argv[1];
  ifstream fin;
  fin.open(filename, fstream::in);

  if (not fin.good()) {
    cout << "It seems like the provided file is not valid, please privide a valid file." << endl;
    return 1;
  }

  // Take input definition
  char in;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      fin >> in;
      occupied[i][j] = in - '0';

      if (topBound == -1 and leftBound == -1 and readCell(i, j)) {
        // We found the start of our blob (assumes that only one blob is present).
        topBound = i;
        leftBound = j;
      }
    }
  }

  // Find the boundaries
  floodFill(topBound, leftBound);

  // Output data
  cout << "Cell Reads: " << numberOfReads << endl;
  cout << "Top: " << topBound << endl;
  cout << "Left: " << leftBound << endl;
  cout << "Bottom: " << botBound << endl;
  cout << "Right: " << rightBound << endl;

  return 0;
}
