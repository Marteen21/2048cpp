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
  void PrintDebug(void) const;
  void MoveTo (const Direction dir);
  void FillDebug (void);
  void Fill(int data[16]);
private:
  bool AddRandomElem (void);
  void SlideTo(const Direction dir);
  void MergeTo (const Direction dir);
};


// 01 02 03 04
// 05 06 07 08
// 09 10 11 12
// 13 14 15 16
