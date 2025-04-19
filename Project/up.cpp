#include "up.h"


int Up::moveTiles(int **grid, int rows, int cols)
{
  //Shift all numbers up
  for(int j=0;j<rows;j++)
    {
      for(int i=0;i<cols;i++)
        {
          if(grid[i][j]==0)
          {
            for(int k=i+1;k<cols;k++)
              {
                if(grid[k][j]!=0)
                {
                  grid[i][j]=grid[k][j];
                  grid[k][j]=0;
                  break;
                }

              }
          }
        }
    }

  int k;

  //Add identical numbers
  for(int j=0;j<rows;j++)
    {
      for(int i=0;i<cols-1;i++)
        {
          //If 2 identical adjacent numbers are found
          if(grid[i][j]==grid[i+1][j])
          {
            grid[i][j]*=2;
            points+=grid[i][j];
            grid[i+1][j]=0;

          //Shift rest of numbers
          for(k=i+1;k<cols-1;k++)
            grid[k][j]=grid[k+1][j];
          grid[k][j]=0;
          }
        }
    }

  
  return points;
}