#ifndef SIMPLE_SHAPE_H_
#define SIMPLE_SHAPE_H_

#include "Shape.h"

class SimpleShape : public Shape {
 public:
  void getPosition(int &row, int &col) { row = rowPos; col = colPos; }
  void setPosition(int row, int col) { rowPos = row; colPos = col; }
  void setColor(int c) { color = 1; }
  int getColor() { return color; }

  virtual void draw() =0;
  virtual void moveShape();

 private:
  int color;
  int rowPos, colPos;
};

#endif