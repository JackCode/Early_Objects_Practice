#include <utility>

#include "QuickSort.h"

void QuickSort::sort(int arr[], int size) {
    quicksort(arr, 0, size-1);
}

void QuickSort::quicksort(int arr[], int start, int end) {
    if (start < end) {
    // Partition array and get pivot point
    int p = partition(arr, start, end);

    // Sort the portion before the pivot
    quicksort(arr, start, p-1);

    // Sort portion after the pivot
    quicksort(arr, p+1, end);
  }
}

int QuickSort::partition(int arr[], int start, int end) {
    // Pivot element is taken to be the element at
  // the start of the subrange to be partitioned.
  int pivotValue = arr[start];
  int pivotPosition = start;

  // Rearrange the rest of the array elements to
  // partition the subrange from start to end.
  for (int pos = start+1; pos <= end; pos++) {
    if (compare(pivotValue, arr[pos])) {
      std::swap(arr[pivotPosition + 1], arr[pos]);
      std::swap(arr[pivotPosition], arr[pivotPosition + 1]);
      pivotPosition++;
    }
  }
  return pivotPosition;
}