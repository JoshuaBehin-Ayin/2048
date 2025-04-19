#ifndef MOVEMENT_H
#define MOVEMENT_H


class Movement{
protected:
  int points=0;
public:

//Pure virtual function to shift all tiles
virtual int moveTiles(int **grid, int rows, int cols)=0;

//Virtual distructor
virtual ~Movement(){}


};

#endif

