#include <iostream>
#include "unindent.h"
#include "indent.h"

int main() {
  std::cout << "\t-------Example of unindent()-------\n";
  std::cout << unindent("bad-code.cpp") << '\n';

  std::cout << "\t-------Examples of indent()-------\n";
  std::cout << "Weird Indents:\n" <<indent("bad-code2.cpp") << '\n';
  std::cout << "Braces Only:\n" <<indent("bad-code5.cpp") << '\n';
  std::cout << "Braces and Loops:\n" <<indent("bad-code4.cpp") << '\n';


  return 0;
}
