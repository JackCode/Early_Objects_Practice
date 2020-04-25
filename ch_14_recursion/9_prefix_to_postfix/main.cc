// Issues cause core dump when spacing is wrong. Maybe fix one day.
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>

void convert_to_postfix(std::istream &prefixStream, 
                        std::ostream &postfixStream);

int main() {
    std::string input;
    std::cout << "Enter prefix expression: ";
    getline(std::cin, input);

    while (input != ""){
        std::istringstream prefixStream(input);
        std::ostringstream postfixStream("");
        convert_to_postfix(prefixStream, postfixStream);
        std::cout << "Postfix: " << postfixStream.str() << "\n\n";
        std::cout << "Enter prefix expression: ";
        getline(std::cin, input);
    }

    return 0;
}


void convert_to_postfix(std::istream &prefixStream, 
                        std::ostream &postfixStream) {
    // Peek through whitespace
    char ch = prefixStream.peek();

    while (isspace(ch)) {
        ch = prefixStream.get();
        ch = prefixStream.peek();
    }

    if (isdigit(ch)) {
        int entry;
        prefixStream >> entry;
        postfixStream << entry << " ";
    } else if (isalpha(ch)) {
        std::string entry;
        prefixStream >> entry;
        postfixStream << entry << " ";
    } else {
        ch = prefixStream.get();
        convert_to_postfix(prefixStream, postfixStream);
        convert_to_postfix(prefixStream, postfixStream);
        postfixStream << ch << " ";
    }
}