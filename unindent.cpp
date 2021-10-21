#include <iostream>
#include <string>
#include <cctype>
#include "unindent.h"

std::string unindent() {
  std::string input;

  while(getline(std::cin, input)) {
    std::cout << removeLeadingSpaces(input) << '\n';
  }

  return 0;
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
