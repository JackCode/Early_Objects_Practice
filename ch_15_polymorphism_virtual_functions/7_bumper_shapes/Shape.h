#ifndef SHAPE_H_
#define SHAPE_H_

#include <ncurses.h>
#include <iostream>

class Shape {
 public:
  Shape() { 
    initscr(); start_color(); 
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(0, COLOR_BLACK, COLOR_BLACK); 
  }
  ~Shape() { endwin(); }
  void getDirection(int &drow, int &dcol) { drow = dRow; dcol = dCol; }

  virtual void setDirection(int drow, int dcol) { dRow = drow; dCol = dcol; }
  virtual void moveShape() =0;

 private:
  int dRow;
  int dCol; 
};

#endif