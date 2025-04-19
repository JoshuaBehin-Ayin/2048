#include <iostream>
#include "grid.h"
#include <ctime>
#include <termios.h>
#include <fstream>
#include <cstdlib>
#include <limits>
using namespace std;
#define STDIN_FILENO 0

int main() {

  srand(time(0));

  // Process arrow key input without pressing enter
  // Code found online as other simpler methods not supported
  struct termios t;
  tcgetattr(STDIN_FILENO, &t);
  t.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &t);

  const int ROWS = 4;
  const int COLS = 4;
  bool endGame = false;
  bool done=false;
  int choice;

  
  
  //Create grid object
  Grid g(ROWS, COLS);

  //Read highscore from txt file
  int highest;
  ifstream fin;
  fin.open("highscore.txt");
  fin>>highest;
  fin.close();

  //Set it to highscore in class
  g.setHighscore(highest);

  
  choice = Grid::menu();
  
  while (!done) {
    

    switch (choice) {
    case 1:
      // Reset Grid elements to 0
      g.newGame();

      g.setScore(0);
      g.setMoveNum(0);
      // Generate 2 random numbers
      g.generateNum();
      g.generateNum();

      // print grid
      cout << g;

      endGame = false;

      while (!endGame) {
        // Get users move
        g.move();

        // Print grid
        cout << g;

        // If user won or lost
        if (!g.gameNotOver() || g.gameWon())
          endGame = true;
      }
      break;
      
    case 2:
      // User quits
      done=true;
      break;
    }//end switch
    if(!done)
    {
    cout<<"Press enter to continue: ";
    getchar();

    //Clears invalid arrow key input if user
    //accidentally presses arrow key after game over
    cin.clear();
    
    //Ignore all previous input - found code online
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<endl;
    
    choice = Grid::menu();
    void(system("clear"));
    }
  }//end while
  cout<<"\nThank you for playing 2048";
}//end main