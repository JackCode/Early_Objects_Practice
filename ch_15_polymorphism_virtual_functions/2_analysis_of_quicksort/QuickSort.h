#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "AbstractSort.h"

class QuickSort : public AbstractSort {
 public:
  virtual void sort(int arr[], int size);
 
 private:
  void quicksort(int arr[], int start, int end);
  int partition(int arr[], int start, int end);
};


#endif