// Recursive function to reverse string
#include <iostream>
#include <string>
#include <utility>

void reverse(std::string &input, int start, int end);

int main() {
    std::string message;

    std::cout << "Enter message to reverse: ";
    getline(std::cin, message);
    reverse(message, 0, message.length());
    std::cout << message << "\n";

    return 0;
}

void reverse(std::string &input, int start, int end) {
    if (start < end) {
        std::swap(input[start], input[end-1]);
        reverse(input, start+1, end-1);
    }
}