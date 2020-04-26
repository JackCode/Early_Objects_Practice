#include "Rectangle.h"

Rectangle::Rectangle(int rowPos, int colPos, int width, int height) {
  setColor(4);
  setPosition(rowPos, colPos);
  this->width = width;
  this->height = height;
  draw();
}

void Rectangle::draw() {
  int rowPos, colPos;
  COORD pos;

  attron(COLOR_PAIR(getColor()));
  getPosition(rowPos, colPos);
  pos.X = colPos; pos.Y = rowPos;

  for (int r = 0; r < height; r++) {
    move(pos.Y, pos.X);
    refresh();
    for (int c = 0; c < width; c++) {
      addch('*');
      refresh();
    }
    addch('\n');
    refresh();
    pos.Y++; 
  }
  attroff(COLOR_PAIR(getColor()));
}