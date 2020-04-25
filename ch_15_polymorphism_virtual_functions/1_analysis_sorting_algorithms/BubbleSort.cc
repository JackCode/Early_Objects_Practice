#include <utility>

#include "BubbleSort.h"

void BubbleSort::sort(int arr[], int size) {
    int pivotPosition = 0;
    bool swapped = true;

    while(swapped) {
        swapped = false;

        for (pivotPosition = 0; pivotPosition < size-1; pivotPosition++) {
            if (compare(arr[pivotPosition], arr[pivotPosition + 1])) {
                std::swap(arr[pivotPosition], arr[pivotPosition + 1]);
                swapped = true;
            }

        }
    }
}