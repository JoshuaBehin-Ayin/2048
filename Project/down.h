#ifndef DOWN_H
#define DOWN_H
#include "movement.h"


class Down: public Movement{
public:
  int moveTiles(int **grid, int rows, int cols);

};

#endif