#include "grid.h"
#include "down.h"
#include "left.h"
#include "movement.h"
#include "right.h"
#include "up.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

Grid::Grid(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;

  // Create dynamically alloacted 2-D array
  grid = new int *[rows];
  for (int i = 0; i < rows; i++)
    grid[i] = new int[cols];
}

Grid::~Grid() {
  for (int i = 0; i < rows; i++)
    delete grid[i];

  delete grid;
}

void Grid::move() {

  // Set score before move
  ofstream fout;
  fout.open("highscore.txt");
  fout << highscore;
  fout.close();

  // Use this to see if users move affects grid
  int oldGrid[4][4];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      oldGrid[i][j] = grid[i][j];
    }
  }

  bool moved = false;
  char c, d, e;
  cout << "Enter your move: ";
  cin >> c;
  cin >> d;
  cin >> e;

  if (c == 27 & d == 91) {
    moved = true;
    if (e == 65)
      setMove = new Up();
    if (e == 66)
      setMove = new Down();
    if (e == 67)
      setMove = new Right();
    if (e == 68)
      setMove = new Left();
  }
  if (moved) {
    // Overload virtual function based on object
    // create and return value to score
    score += setMove->moveTiles(grid, rows, cols);

    // Deallocate memory
    delete setMove;

    // to ignore return value
    void(system("clear"));

    if (validMove(oldGrid)) {
      moveNum++;
      generateNum();
      if (score > highscore)
        highscore = score;
    }
  }
}

int Grid::menu() {
  int choice;
  cout << "<<<<<<2048>>>>>>" << endl;
  cout << "1. Play Game" << endl;
  cout << "2. Quit" << endl;

  do {
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (choice != 1 && choice != 2)
      cout << "Error: Invalid Input" << endl;

  } while (choice != 1 && choice != 2);
  return choice;
}

void Grid::newGame() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      grid[i][j] = 0;
  }
}

void Grid::generateNum() {
  for (int i = 0; i < rows*cols; i++) {
    int randNum = rand() % 101;
    if (randNum > 10)
      randNum = 2;

    else
      randNum = 4;

    int randRow = rand() % rows;
    int randCol = rand() % cols;

    if (grid[randRow][randCol] == 0) {
      grid[randRow][randCol] = randNum;
      break;
    }
  }
}

bool Grid::validMove(int oldGrid[4][4]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (oldGrid[i][j] != grid[i][j])
        return true;
    }
  }
  cout << "\nERROR: Invalid Move" << endl;
  return false;
}

bool Grid::gameNotOver() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {

      if (grid[i][j] == 0)
        return true;

      else if (i < 3 && grid[i][j] == grid[i + 1][j])
        return true;

      else if (j < 3 && grid[i][j] == grid[i][j + 1])
        return true;
    }
  }

  cout << "\nGame Over!" << endl;
  return false;
}

bool Grid::gameWon() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 2048) {
        cout << "You Win!"<<endl;
        return true;
      }
    }
  }
  return false;
}

ostream &operator<<(ostream &out, const Grid &g) {
  int leftw;
  int rightw;

  out << "\nScore: " << g.score << endl;
  out << "Highscore: " << g.highscore << endl;
  out << "Moves: " << g.moveNum << endl;
  for (int i = 0; i <= g.rows*g.cols; i++) {
    for (int j = 0; j < g.rows; j++) {
      int num = g.grid[i / g.rows][j];
      if (i % g.rows == 0) {
        out << "• • • • • • • • • • • • • • • • •";
        break;
      }

      else if (i % 2 == 1) {
        out << "•       •       •       •       •";
        break;
      }

      else {

        if (num < 10) {
          leftw = 4;
          rightw = 6;
        } else {
          leftw = 5;
          rightw = 5;
        }

        if (num == 0)
          out << "•" << setw(leftw) << " " << setw(rightw);
        else
          out << "•" << setw(leftw) << num << setw(rightw);

        if (j == 3)
          out << "•";

      } // end else

    } // end for j
    out << endl;
  } // end for i
  return out;
} // end function