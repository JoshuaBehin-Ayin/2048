#include "left.h"

int Left::moveTiles(int **grid, int rows, int cols)
{
  //Shift all numbers left
  for(int i=0;i<rows;i++)
    {
      for(int j=0;j<cols;j++)
        {
          if(grid[i][j]==0)
          {
            for(int k=j+1;k<cols;k++)
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
      for(int j=0;j<cols-1;j++)
        {
          //If 2 identical adjacent numbers are found
          if(grid[i][j]==grid[i][j+1])
          {
            
            grid[i][j]=grid[i][j]+grid[i][j+1];
            points+=grid[i][j];
            grid[i][j+1]=0;
          
          //Shift rest of numbers
          for(k=j+1;k<cols-1;k++)
            grid[i][k]=grid[i][k+1];
          grid[i][k]=0;
          
          }
        }
     
    }
  
  return points;
}