// Recursively calculates sum of int array entries
#include <iostream>

int get_sum(int arr[], int arrSize);

int main() {
    const int ARR_SIZE = 10;
    int array[10];

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter integer: ";
        std::cin >> array[i];
    }

    std::cout << "Sum: " << get_sum(array, ARR_SIZE) << "\n";

    return 0;
}

int get_sum(int arr[], int arrSize) {
    if (arrSize <= 0)
        return 0;
    
    return get_sum(arr, arrSize - 1) + arr[arrSize - 1]; 
}