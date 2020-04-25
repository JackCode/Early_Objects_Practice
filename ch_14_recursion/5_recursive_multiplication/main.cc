// Using recursion to multiply two ints
#include <iostream>

int multiply(int x, int y);

int main() {
    int x, y;

    std::cout << "Enter two numbers to multiply: ";
    std::cin >> x >> y;
    std::cout << x << " * " << y << " = " << multiply(x, y) << "\n";

    return 0;
}

int multiply(int x, int y) {
    if (y > 1)
        return x + multiply(x, y - 1);
    return x;    
}