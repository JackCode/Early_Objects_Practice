// This is not a very friendly program. Written on a linux system
// but the challenge/textbook are designed for Windows.

#include <iostream>
#include <unistd.h>

#include "Rectangle.h"

int main() {
  int count = 0;
  Rectangle rectLeft(5, 0, 4, 7);
  Rectangle rectRight(5, 76, 4, 7);
  rectLeft.setDirection(0, 1);
  rectRight.setDirection(0, -1);
  rectRight.draw();
  rectLeft.draw();

  while (count != 10) {
    for (int k = 0; k < 72; k++)
    {
      if (k >= 36) {
        rectRight.setDirection(0, 1);
        rectLeft.setDirection(0, -1);
      }
      usleep(76000);
      rectLeft.moveShape();
      usleep(40000);
      rectRight.moveShape();
    }
    rectLeft.setDirection(0, 1);
    rectRight.setDirection(0, -1);
    count++;
  }

	return 0;
}