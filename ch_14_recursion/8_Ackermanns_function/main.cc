// Ackermann Function
#include <iostream>

int ackermann(int m, int n);

int main() {
    int array[7][2] {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 2}, {3, 2}};

    for (int i = 0; i < 7; i++) {
        std::cout << "A(" << array[i][0] << ", " << array[i][1] << ") = " 
                  << ackermann(array[i][0], array[i][1]) << "\n";
    }

    return 0;
}

int ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n -1));
}