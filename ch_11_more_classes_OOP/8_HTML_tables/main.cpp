#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "HTMLTable.h"

typedef HTMLTable::Student Student;

void get_students(HTMLTable& data, int numStudents);

int main() {
  HTMLTable firstPeriod;
  vector<string> headers {"Name", "Score"};
  int numStudents;

  firstPeriod.set_headers(headers);

  std::cout << "How many students: ";
  std::cin >> numStudents;
  get_students(firstPeriod, numStudents);
  
  ofstream outputFile("table.html");
  outputFile << firstPeriod;
  outputFile.close();

  std::cout << firstPeriod << endl;

  system("firefox ./table.html");

  return 0;
}

void get_students(HTMLTable& data, int numStudents) {
  Student *ptr = new Student;

  for (int count = 0; count < numStudents; count++) {
    std::cout << "Student name: ";
    std::cin.ignore();
    getline(std::cin, ptr->studentName);
    std::cout << "Student score: ";
    cin >> ptr->studentScore;
    
    data.add_row(*ptr);
  }

  delete ptr;
}