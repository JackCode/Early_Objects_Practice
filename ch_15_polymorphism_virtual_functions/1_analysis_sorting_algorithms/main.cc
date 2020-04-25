#include <iostream>

#include "BubbleSort.h"

int main() {
    const int ARRAY_SIZE = 10;
    int array[] = {3, 90, 54, 13, 1, 76, 84, 32, 12, 99};
    BubbleSort bs;

    for (int i = 0; i < ARRAY_SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << "\n";

    bs.sort(array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
        std::cout << array[i] << " ";

    std::cout << "\n";
    std::cout << "Number of comparisons: " << bs.get_num_compares() << "\n";

    return 0;
}