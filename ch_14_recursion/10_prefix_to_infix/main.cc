#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>

void convert_to_postfix(std::istream &prefixStream, 
                        std::ostream &infixStream, bool prevIsOp);

int main() {
    std::string input;
    std::cout << "Enter prefix expression: ";
    getline(std::cin, input);

    while (input != ""){
        std::istringstream prefixStream(input);
        std::ostringstream infixStream("");
        convert_to_postfix(prefixStream, infixStream, false);
        std::cout << "Infix: " << infixStream.str() << "\n\n";
        std::cout << "Enter prefix expression: ";
        getline(std::cin, input);
    }

    return 0;
}

void convert_to_postfix(std::istream &prefixStream, 
                        std::ostream &infixStream, bool prevIsOp) {
    // Peek through whitespace
    char ch = prefixStream.peek();

    while (isspace(ch)) {
        ch = prefixStream.get();
        ch = prefixStream.peek();
    }

    if (isdigit(ch)) {
        int entry;
        prefixStream >> entry;
        infixStream << entry << " ";
    } else if (isalpha(ch)) {
        std::string entry;
        prefixStream >> entry;
        infixStream << entry << " ";
    } else {
        ch = prefixStream.get();
        if(prevIsOp)
            infixStream << "(";
        convert_to_postfix(prefixStream, infixStream, true);
        infixStream << ch << " ";
        convert_to_postfix(prefixStream, infixStream, false);
        if(prevIsOp)
            infixStream << "\b) ";
    }
}