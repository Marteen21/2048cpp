#include "field.hpp"
#include <iostream>



Field::Field (){
  this->value = 0;
  this->northNeighbour = nullptr;
  this->eastNeighbour = nullptr;
  this->southNeighbour = nullptr;
  this->westNeighbour = nullptr;
}

int Field::GetValue () const{
	if (this != nullptr)
		return this->value;
	else
		return -1;
}

void Field::SetValue (int v){
  this->value = v;
}

bool Field::HasNeighbour (const Direction dir) const {
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

Field* Field::GetNeighbour (const Direction dir) const {
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

void Field::SetNeightbour (const Direction dir, Field* neighbour) {
  if (neighbour == nullptr || neighbour == this)
    throw std::runtime_error ("wrong neighbour");
  switch (dir){
    case Direction::North:
      this->northNeighbour = neighbour;
      break;
    case Direction::East:
      this->eastNeighbour = neighbour;
      break;
    case Direction::South:
      this->southNeighbour = neighbour;
      break;
    case Direction::West:
      this->westNeighbour = neighbour;
      break;
    default:
      break;
  }
}



void Field::MergeFrom (const Direction dir) {
  Field* nextNotEmptyNeighbour = GetNeighbour (dir);
  while (nextNotEmptyNeighbour != nullptr) {
    if (nextNotEmptyNeighbour->value == 0) {
      nextNotEmptyNeighbour = nextNotEmptyNeighbour->GetNeighbour (dir);
	} else if (this->value == 0) {
		this->value = nextNotEmptyNeighbour->value;
		nextNotEmptyNeighbour->value = 0;
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
