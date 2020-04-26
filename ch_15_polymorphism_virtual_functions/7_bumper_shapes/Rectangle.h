#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "SimpleShape.h"

class Rectangle : public SimpleShape {
 public:
  struct COORD {
    short X, Y;
  };
  
  Rectangle(int rowPos, int colPos, int width, int height);
  virtual void draw();

 private:
  int width, height;
};

#endif