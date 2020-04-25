// This program is created prior to the chapter on templates,
// therefore it will just overload the function multiple times.
// Will update when I learn about templates
// Create a template version of quicksort algorithm

#include <iostream>
#include <utility> // For use of swap function

void quicksort(int arr[], int start, int end);
int partition (int arr[], int start, int end);

int main() {
  int array[10] {17, 53, 9, 2, 30, 1, 82, 64, 26, 5};

  for (int i = 0; i < 10; i++)
    std::cout << array[i] << " ";

  std::cout << "\n";

  quicksort(array, 0, 9);

  for (int i = 0; i < 10; i++)
    std::cout << array[i] << " ";

  std::cout << "\n";

  return 0;
}

void quicksort(int arr[], int start, int end) {
  if (start < end) {
    // Partition array and get pivot point
    int p = partition(arr, start, end);

    // Sort the portion before the pivot
    quicksort(arr, start, p-1);

    // Sort portion after the pivot
    quicksort(arr, p+1, end);
  }
}

int partition(int arr[], int start, int end) {
  // Pivot element is taken to be the element at
  // the start of the subrange to be partitioned.
  int pivotValue = arr[start];
  int pivotPosition = start;

  // Rearrange the rest of the array elements to
  // partition the subrange from start to end.
  for (int pos = start+1; pos <= end; pos++) {
    if (arr[pos] < pivotValue) {
      std::swap(arr[pivotPosition + 1], arr[pos]);
      std::swap(arr[pivotPosition], arr[pivotPosition + 1]);
      pivotPosition++;
    }
  }
  return pivotPosition;
}

