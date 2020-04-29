#include <iostream>
#include <string>
#include <sstream>
#include <stack>

double evalPostfix(std::istringstream &inputStream);

int main() {
  std::string input;
  std::cout << "Enter a postfix expression to evaluate,"
            << " \nor a blank line to quit the program: ";
  getline(std::cin, input);

  while (input.size() != 0) {
    std::istringstream inputExp(input);
    std::cout << input << " = " << evalPostfix(inputExp) << "\n";
    std::cout << "Enter a postfix expression to evaluate: ";
    getline(std::cin, input);
  }
  return 0;
}

double evalPostfix(std::istringstream &inputStream) {
  std::stack<double> postStack;
  char ch;
  double result1, result2;

  ch = inputStream.peek();

  while (ch != EOF) {

    if (isspace(ch)) {
      ch = inputStream.get();
      ch = inputStream.peek();
      continue;
    }

    if (isdigit(ch)) {
      inputStream >> result1;
      postStack.push(result1);
      ch = inputStream.peek();
      continue;
    }

    result2 = postStack.top();
    postStack.pop();
    result1 = postStack.top();
    postStack.pop();

    switch (ch) {
      case '+':
        postStack.push(result1+result2);
        break;
      case '-':
        postStack.push(result1-result2);
        break;
      case '*':
        postStack.push(result1*result2);
        break;
      case '/':
        postStack.push(result1/result2);
        break;
      default:
        std::cout << "Bad input expression.";
        std::exit(1);
    }
    inputStream.get(ch);
    ch = inputStream.peek();
  }
  return postStack.top();
}