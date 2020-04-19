#ifndef HTML_TABLE_H
#define HTML_TABLE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class HTMLTable {
 public:
  struct Student {
    string studentName;
    int studentScore;
  };

  HTMLTable(){};
  HTMLTable(const vector<Student> &students) { this->classroom = students; }

  void set_headers(const vector<string> &headers) { this->headers = headers; }
  void add_row(const Student &row) { this->classroom.push_back(row); }
  
  friend ostream & operator<< (ostream &out, HTMLTable htmltable);

 private:
  vector<Student> classroom;

  // HTML Components
  vector<string> headers;
  void writeRow(ostream &out, string tag, vector<string> row);
  void writeRow(ostream &out, string tag, Student row);
};

#endif