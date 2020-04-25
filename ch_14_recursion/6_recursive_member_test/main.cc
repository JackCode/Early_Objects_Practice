// Recusively finds a value in an array
#include <iostream>

bool isMember(int arr[], int arrSize, int needle);

int main() {
    const int ARRAY_SIZE = 5;
    int array[ARRAY_SIZE];
    int needle;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Enter integer: ";
        std::cin >> array[i];
    }

    std::cout << "Enter integer to be searched for: ";
    std::cin >> needle;

    if (isMember(array, ARRAY_SIZE, needle))
        std::cout << "Yes, it is in the array\n";
    else 
        std::cout << "No, it is not in the array.\n";

    return 0;
}

bool isMember(int arr[], int arrSize, int needle) {
    if (arrSize <= 0)
        return false;
    
    if (arrSize > 1)
        return (arr[arrSize-1] == needle) || (isMember(arr, arrSize-1, needle));
    return arr[arrSize-1] == needle;
}