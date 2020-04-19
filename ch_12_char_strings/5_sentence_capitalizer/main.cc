#include <iostream>

void capitalize_first(char *cstring);

int main() {
  char message[] = "hello. i like dogs. what is your name?";
  
  std::cout << message << "\n";
  capitalize_first(message);
  std::cout << message << "\n";

  return 0;
}

void capitalize_first(char *cstring) {
  *cstring = toupper(*cstring);
  cstring++;
  
  while (*cstring != '\0') {
    if (isspace(*cstring) && ispunct(*(cstring-1))) {
      *(cstring+1) = toupper(*(cstring+1));
    }
    cstring++;
  }
}