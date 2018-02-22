#include "field.hpp"



Field::Field (){
  this->value = 0;
}

int Field::GetValue () const{
  return this->value;
}

void Field::SetValue (int v){
  this->value = v;
}

bool Field::HasNeighbour (Direction dir) const {
  switch (dir){
    case Direction::North:
      return northNeighbour != nullptr;
    case Direction::East:
      return eastNeighbour != nullptr;
    case Direction::South:
      return southNeighbour != nullptr;
    case Direction::West:
      return westNeighbour != nullptr;
    default:
      return false;
  }
}

Field* Field::GetNeighbour (Direction dir) const {
  switch (dir){
    case Direction::North:
      return northNeighbour;
    case Direction::East:
      return eastNeighbour;
    case Direction::South:
      return southNeighbour;
    case Direction::West:
      return westNeighbour;
    default:
      return nullptr;
  }
}

void Field::SetNeightbour (Direction dir, Field* neighbour) {
  switch (dir){
    case Direction::North:
      this->westNeighbour = neighbour;
      break;
    case Direction::East:
      this->westNeighbour = neighbour;
      break;
    case Direction::South:
      this->westNeighbour = neighbour;
      break;
    case Direction::West:
      this->westNeighbour = neighbour;
      break;
    default:
      break;
  }
}



void Field::MergeFrom (Direction dir) {
  Field* nextNotEmptyNeighbour = GetNeighbour (dir);
  while (nextNotEmptyNeighbour != nullptr) {
    if (nextNotEmptyNeighbour->value == 0) {
      nextNotEmptyNeighbour = nextNotEmptyNeighbour->GetNeighbour (dir);
    } else if (nextNotEmptyNeighbour->value == this->value) {
      this->value++;
      nextNotEmptyNeighbour->value = 0;
      return;
    } else if (nextNotEmptyNeighbour == this->GetNeighbour(dir)){
      return;
    } else {
      this->GetNeighbour (dir)-> value = nextNotEmptyNeighbour->value;
      nextNotEmptyNeighbour->value = 0;
    }
  }

}
