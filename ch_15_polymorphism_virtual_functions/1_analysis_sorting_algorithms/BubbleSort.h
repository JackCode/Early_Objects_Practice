#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "AbstractSort.h"

class BubbleSort : public AbstractSort {
 public:
  virtual void sort(int arr[], int size);
};

#endif