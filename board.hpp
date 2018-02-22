#include "field.hpp"

class Board {
private:
  Field* fields[16];
public:
  Board (void);
  ~Board (void);

  Field* GetField (int i, int j);
  int GetFieldValue (int i, int j) const;
  void Print (void) const;
  void MoveTo (Direction dir);
private:
  bool AddRandomElem (void);
  void MergeTo (Direction dir);
};


// 01 02 03 04
// 05 06 07 08
// 09 10 11 12
// 13 14 15 16
