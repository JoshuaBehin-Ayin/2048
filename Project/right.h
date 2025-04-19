#ifndef RIGHT_H
#define RIGHT_H
#include "movement.h"


class Right: public Movement{
public:
  int moveTiles(int **grid, int rows, int cols);

};

#endif