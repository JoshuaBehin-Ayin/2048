#ifndef LEFT_H
#define LEFT_H
#include "movement.h"


class Left: public Movement{
public:
  int moveTiles(int **grid, int rows, int cols);

};

#endif