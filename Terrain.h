
/*  a terrain is a matrix of 0 and 1
   0 for background
   1 for ground

   */

#include <string>
#include <vector>
#include "SDL.h"
#include "Cell.h"

using namespace std;

class Terrain{
  private:
      //matrix
      //int height;
      //int weight;
      //int[][] matrix;

      vector<SDL_Rect> grounds;

      string pathToImage = "../images/ground1.bmp";


  public:
      Terrain(); // can be initialized with a binary image file ?

      //vector<SDL_Rect> getGrounds();
      vector<vector<Cell>> getGround(){}

      string getPathToImage();

      // return the type of the location : if it is a ground or background
      // or something else ?
      //int getTypeAtPosition(int xLocation, int yLocation);
    
};