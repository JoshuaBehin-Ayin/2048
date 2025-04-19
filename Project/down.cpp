#include "down.h"
#include <iostream>
using namespace std;

int Down::moveTiles(int **grid, int rows, int cols) {
  // Shift all numbers down
  for (int j = 0; j < rows; j++) {
    for (int i = cols-1; i >= 0; i--) {
      if (grid[i][j] == 0) {
        for (int k = i - 1; k >= 0; k--) {
          if (grid[k][j] != 0) {
            grid[i][j] = grid[k][j];
            grid[k][j] = 0;
            break;
          }
        }
      }
    }
  }

  int k;

  // Add identical numbers
  for (int j = 0; j < rows; j++) {
    for (int i = cols-1; i > 0; i--) {
      // If 2 identical adjacent numbers are found
      if (grid[i][j] == grid[i - 1][j]) {
        grid[i][j] *= 2;
        points += grid[i][j];
        grid[i - 1][j] = 0;

        // Shift rest of numbers
        for (k = i - 1; k > 0; k--)
          grid[k][j] = grid[k - 1][j];
        grid[k][j] = 0;
       
      }
    }
  }
  return points;
}