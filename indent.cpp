#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "indent.h"

/*
TESTING

int main() {
  std::cout << indent("bad-code.cpp") << '\n';
	std::cout << indent("bad-code5.cpp") << '\n';


  return 0;
}
*/

std::string indent(std::string in) {
	std::fstream file;
	std::string input;
	std::string output = "";

	int tabs = 0;
	int temp_tabs = tabs;
	file.open(in);

	if (file.is_open()) {
		while (getline(file, input)) {
			input = removeIndents(input);

			if (input[0] == '}') {
				tabs--;
			} else if (instanceChar(input, '{') && instanceChar(input, '}')) {
				temp_tabs = tabs;
			} else if (instanceChar(input, '}')) {
				tabs--;
			}

			for (int i = 0; i < tabs; i++) {
				output += '\t';
			}

			output += input;
			output += '\n';

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
		file.close();
	} else {
		std::cerr << "Unable to open file.\n";
	}
	return output;
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

std::string removeIndents(std::string line) {
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
