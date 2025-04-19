#include "right.h"


int Right::moveTiles(int **grid, int rows, int cols)
{ 
  //Shift all numbers right
  for(int i=0;i<rows;i++)
    {
      for(int j=cols-1;j>=0;j--)
        {
          if(grid[i][j]==0)
          {
            for(int k=j-1;k>=0;k--)
              {
                if(grid[i][k]!=0)
                {
                  grid[i][j]=grid[i][k];
                  grid[i][k]=0;
                  break;
                }

              }
          }
        }
    }

  int k;

  //Add identical numbers
  for(int i=0;i<rows;i++)
    {
      for(int j=cols-1;j>=0;j--)
        {
          if(grid[i][j]==grid[i][j-1])
          {
            grid[i][j]=grid[i][j]+grid[i][j-1];
            points+=grid[i][j];
            grid[i][j-1]=0;
          

          for(k=j-1;k>0;k--)
            grid[i][k]=grid[i][k-1];
          grid[i][k]=0;
          }
        }
    }

  return points;
}