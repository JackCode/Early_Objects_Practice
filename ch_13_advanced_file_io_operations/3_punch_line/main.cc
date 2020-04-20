#include <iostream>
#include <fstream>
#include <string>

void get_joke(std::ifstream& jokeFile);
void get_punchline(std::ifstream& punchlineFile);

int main() {
  std::ifstream jokeFile("joke.dat"), 
                punchlineFile("punchline.dat");

  if (!jokeFile || !punchlineFile) {
    std::cout << "Unable to open one of the files.\n";
    return 0;
  }

  get_joke(jokeFile);
  get_punchline(punchlineFile);
  std::cout << std::endl;

  return 0;
}

void get_joke(std::ifstream& jokeFile) {
  std::string buffer;
  getline(jokeFile, buffer);
  std::cout << buffer << std::endl;
}

void get_punchline(std::ifstream& punchlineFile) {
  std::string buffer;
  char ch;

  punchlineFile.seekg(-1L, std::ios::end);
  ch = punchlineFile.peek();

  while (ch != '\n'){
    punchlineFile.seekg(-1L, std::ios::cur);
    ch = punchlineFile.peek();
  }

  punchlineFile.seekg(1L, std::ios::cur);

  getline(punchlineFile, buffer);
  std::cout << buffer << std::endl;
}