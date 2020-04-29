#include <iostream>
#include <string>
#include <stack>

bool isBalanced(std::string &input); // Checks if delimiters are balanced

int main() {
  std::string input;
  std::cout << "Enter string to check if delimiters are balanced,\n"
            << " or a blank line to quit program: ";
  getline(std::cin, input);

  while (input.length() != 0) {
    if (isBalanced(input)) {
      std::cout << "Yes, delimiters are balanced.";
    } else {
      std::cout << "No, delimiters are not balanced.";
    }

    std::cout << "\n\n";
    std::cout << "Enter string to check: ";
    getline(std::cin, input);
  }

  return 0;
}

bool isBalanced(std::string &input) {
  std::stack<char> delStack;
  
  for (int i = 0; i < input.length(); i++) {
    switch(input[i]) {
      case '(':
      case '[':
      case '{':
        delStack.push(input[i]);
        break;
      case ')':
        if (delStack.empty()) return false;
        if (delStack.top() == '(') { 
          delStack.pop();
          break;
        }
      case ']':
        if (delStack.empty()) return false;
        if (delStack.top() == '[') { 
          delStack.pop();
          break;
        }
      case '}':
        if (delStack.empty()) return false;
        if (delStack.top() == '{') { 
          delStack.pop();
          break;
        }
        return false;
    }
  }
  return delStack.empty();
}