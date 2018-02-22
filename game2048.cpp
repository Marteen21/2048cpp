#include <iostream>
#include "board.hpp"
int main (){
  std::cout<< "2048 Game written in cpp"<<std::endl;
  Board myBoard = Board();
  char c;
  while (true) {
    myBoard.Print ();
    std::cin >> c;
    switch (c){
      case 'w':
        myBoard.MoveTo (Direction::North);
        break;
      case 'a':
        myBoard.MoveTo (Direction::East);
        break;
      case 's':
        myBoard.MoveTo (Direction::South);
        break;
      case 'd':
        myBoard.MoveTo (Direction::West);
        break;
      default:
        break;
    }
  }
  return 0;
}
