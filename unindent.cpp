#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "unindent.h"

/*
TESTING

int main() {
  std::cout << unindent("bad-code.cpp") << '\n';
  std::cout << unindent("bad-code3.cpp") << '\n';


  return 0;
}
*/

std::string unindent(std::string in) {
  std::fstream file;
  std::string input;
  std::string output = "";

  file.open(in);
  if (file.is_open()) {
    while(getline(file, input)) {
      output += removeLeadingSpaces(input);
      output += '\n';
    }

    file.close();
  } else {
    std::cerr << "Unable to open file\n";
  }


  return output;
}

std::string removeLeadingSpaces(std::string line) {
  std::string output = "";
  int len = line.length();
  int spaces = 0;

  for (int i = 0; i < len; i++) {
    if (!isspace(line[i])) { //should "activate" after first block of spaces are done
      spaces++;
    }

    if (spaces > 0) { //if first block of spaces/indents have been parsed thru
      output += line[i];
    }

  }

  return output;
}
