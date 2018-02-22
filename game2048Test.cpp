#include <iostream>
#include "board.hpp"
int main (){
  std::cout<< "2048 Game written in cpp"<<std::endl;
  Board myBoard = Board();
  myBoard.Print ();
  return 0;
}
