
/*  a terrain is a matrix of 0 and 1
   0 for background
   1 for ground

   */

using<string>

using namespace std

class Terrain{
  private:
      //matrix
      int height;
      int weight;
      int[][] matrix;

      string pathToImage;


  public:
      Terrain(); // can be initialized with a binary image file ?

      // return the type of the location : if it is a ground or background
      // or something else ?
      int getTypeAtPosition(int xLocation, int yLocation);
    





}