#ifndef GRID_H
#define GRID_H

#include "movement.h"
#include <iostream>
using namespace std;

class Grid {
private:
  int rows;
  int cols;
  int **grid;
  int score = 0;
  int moveNum = 0;
  int highscore;
  Movement *setMove;

public:
  //Paramerterized constructor
  Grid(int rows, int cols);

  //Destructor
  ~Grid();

  //Gets users arrow key move and updates stats
  void move();

  //Sets grid elements to 0 
  void newGame();

  //Generates num, either 2 or 4 and
  //places it in empty box
  void generateNum();

  //Setters
  void setHighscore(int h) { highscore = h; }
  void setScore(int s) { score = s; }
  void setMoveNum(int m) { moveNum = m; }

  //Menu returns choice
  static int menu();

  //Check if game is not over
  bool gameNotOver();

  //Checks if game won
  bool gameWon();

  //Checks to see if users move changes grid
  bool validMove(int oldGrid[4][4]);

  //Overloading stream insertion operator to print grid
  friend ostream &operator<<(ostream &out, const Grid &g);
};

#endif
