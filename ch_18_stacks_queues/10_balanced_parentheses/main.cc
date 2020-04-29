#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string &input); // Checks if parentheses are balanced

int main() {
  std::string input;
  std::cout << "Enter string to check if parenthesis are balanced,\n"
            << " or a blank line to quit program: ";
  getline(std::cin, input);

  while (input.length() != 0) {
    if (isBalanced(input)) {
      std::cout << "Yes, parentheses are balanced.";
    } else {
      std::cout << "No, parenthesis are not balanced.";
    }

    std::cout << "\n\n";
    std::cout << "Enter string to check: ";
    getline(std::cin, input);
  }

  return 0;
}

bool isBalanced(std::string &input) {
  std::stack<char> parenthStack;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == '(') {
      parenthStack.push(input[i]);
    } else if (input[i] == ')') {
      if (parenthStack.empty())
        return false;
      else
        parenthStack.pop();
    }
  }
  return parenthStack.empty();
}