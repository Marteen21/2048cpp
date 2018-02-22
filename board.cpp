#include "board.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"

Board::Board () {
  for (int i = 0; i < 16; i++) {
    this->fields[i] = new Field();
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j > 0) {
        this->fields[i*4+j]->SetNeightbour(Direction::West, this->fields[i*4+(j-1)]);
      }
      if (j < 3) {
        this->fields[i*4+j]->SetNeightbour(Direction::East, this->fields[i*4+(j+1)]);
      }
      if (i > 0){
        this->fields[i*4+j]->SetNeightbour(Direction::North, this->fields[(i-1)*4+j]);
      }
      if (i < 3){
        this->fields[i*4+j]->SetNeightbour(Direction::South, this->fields[(i+1)*4+j]);
      }
    }
  }
}

Board::~Board () {
  for (int i = 16; i > 0; ) {
    delete fields[--i];
  }
}

Field* Board::GetField (int i, int j) {
  return this->fields[i*4+j];
}

int Board::GetFieldValue (int i, int j) const {
  return this->fields[i*4+j]->GetValue ();
}

void Board::Print () const {
  std::cout << std::endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << GetFieldValue(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

bool Board::AddRandomElem () {
  std::vector<int> indices;
  for (int i = 0; i<16; i++) {
    if (this->fields[i]->GetValue () == 0){
      indices.push_back (i);
    }
  }
  if (indices.size ()> 0) {
    int r = *select_randomly(indices.begin(), indices.end());
    this->fields[indices[r]]->SetValue (1);
    return true;
  } else {
    throw std::runtime_error ("game over");
    return false;
  }
}

void Board::MoveTo (Direction dir) {
  MergeTo(dir);
  AddRandomElem ();
}

Direction GetOppositeDirection (Direction dir) {
  switch (dir){
    case Direction::North:
      return Direction::South;
    case Direction::East:
      return Direction::West;
    case Direction::South:
      return Direction::North;
    case Direction::West:
      return Direction::East;
    default:
      return Direction::North;
  }
}

void Board::MergeTo (Direction dir) {
  bool verticalMerge = dir == Direction::North || Direction::South;
  bool positiveDirection = dir == Direction::South || Direction::East;
  int x,y;
  if (positiveDirection) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        x = verticalMerge ? i : j;
        y = verticalMerge ? j : i;
        GetField(x,y)->MergeFrom(GetOppositeDirection(dir));
      }
    }
  } else {
    for (int i = 3; i > 0; i--) {
      for (int j = 3; j > 0; j--) {
        x = verticalMerge ? i : j;
        y = verticalMerge ? j : i;
        GetField(x,y)->MergeFrom(GetOppositeDirection(dir));
      }
    }
  }
}
