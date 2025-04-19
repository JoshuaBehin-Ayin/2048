#ifndef UP_H
#define UP_H
#include "movement.h"


class Up: public Movement{
public:
  int moveTiles(int **grid, int rows, int cols);

};

#endif