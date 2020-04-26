#include "SimpleShape.h"

void SimpleShape::moveShape() {
  int dRow, dCol; // Direction of  motion
  int savedColor = color;

  // Erase currently drawn shape
  clear();
  refresh();

  // Move shape coords to next position
  getDirection(dRow, dCol);
  rowPos += dRow;
  colPos += dCol;

  // Redraw shape
  color = savedColor;
  draw();
}