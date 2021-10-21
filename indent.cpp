#include <iostream>
#include <cctype>
#include <string>
//#include "indent.h"
//#include "unindent.h"

bool instanceChar(std::string line, char c);
int countChar(std::string line, char c);
std::string removeLeadingSpaces(std::string line);

int main() {
	std::string input;

	int tabs = 0;

	while (getline(std::cin, input)) {
		input = removeLeadingSpaces(input);

		if ((input[0] == '}')) {
			tabs--;
		} else if (instanceChar(input, '{') && instanceChar(input, '}')) {
			tabs = tabs;
		} else if (instanceChar(input, '}')) {
			tabs--;
		}

		for (int i = 0; i < tabs; i++) {
			std::cout << '\t';
		}

		std::cout << input << '\n';

		if (countChar(input, '}') > 1) {
			for (int i = 0; i < countChar(input, '}'); i++) {
				tabs--;
			}

			if (instanceChar(input, '{')) {
				tabs++;
			}
		}

		if (countChar(input, '{') > 1) {
			for (int i = 0; i < countChar(input, '{'); i++) {
				tabs++;
			}

			if (instanceChar(input, '}')) {
				tabs--;
			}
		} else if (instanceChar(input, '{') && !instanceChar(input, '}')) {
			tabs++;
		} else if ((input[0] == '}') && instanceChar(input, '{')) {
			tabs++;
		}

	} 
	return 0;
}

bool instanceChar(std::string line, char c) {
	bool occurence = false;
	int len = line.length();

	for (int i = 0; i < len; i++) {
		if (line[i] == (int)c) {
			occurence = true;
		}
	}

	return occurence;
}

int countChar(std::string line, char c) {
	int occurence = false;
	int len = line.length();

	for (int i = 0; i < len; i++) {
		if (line[i] == (int)c) {
			occurence++;
		}
	}

	return occurence;
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