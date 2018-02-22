enum Direction{North, East, South, West};

class Field {
public:
private:
  int value;
  Field* northNeighbour;
  Field* eastNeighbour;
  Field* southNeighbour;
  Field* westNeighbour;

public:
  Field (void);

  int GetValue (void) const;
  void SetValue (int v);

  bool HasNeighbour (const Direction dir) const;
  Field* GetNeighbour (const Direction dir) const;
  void SetNeightbour (const Direction dir, Field* neighbour);

  void MergeFrom (const Direction dir);
};
