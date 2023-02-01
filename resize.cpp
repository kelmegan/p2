// Project UID af1f95f547e44c8ea88730dfb185559d


#include <iostream>
#include "processing.h"
#include <fstream>
#include <cstdlib>
using namespace std;


int main(int argc, char *argv[]) {
  Image *img = new Image;
  ifstream fin;
  ofstream fout;
  fin.open(argv[1]);
  fout.open(argv[2]);
  if (!fin.is_open()) {
    cout << "Error opening file: " << *argv[1] << endl;
    return 1;
  }
  Image_init(img, fin);


  int newHeight = 0;
  int newWidth = atoi(argv[3]);
  if(argc == 4){
    newHeight = Image_height(img);
  }else if(argc == 5){
    newHeight = atoi(argv[4]);
  }
  if((!((0 < newWidth) && (newWidth <= Image_width(img))))) //|| (!((0 < newHeight) && (newHeight <= Image_height(img)))) || ((argc !=4) || (argc != 5)))
  {
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
     << "WIDTH and HEIGHT must be less than or equal to original" << endl;
     return -1;
  }


  seam_carve(img, newWidth, newHeight);
  Image_print(img, fout);
  fin.close();
  fout.close();
}
