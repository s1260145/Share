//s1260145
#include <cstdlib> // for free
#include <iostream> // for std::cout, std::endl and <<
#include "int_str.h"

int main(void) {
  int i1 = 10;
  char* c1 = intToStr(i1);
  std::cout << c1 << std::endl;

  char* c2 = (char*)"10";
  int i2 = strToInt(c2);
  std::cout << i2 << std::endl;

  int i3 = -20;
  char* c3 = intToStr(i3);
  std::cout << c3 << std::endl;
  free(c3);

  char* c4 = (char*)"-20";
  int i4 = strToInt(c4);
  std::cout << i4 << std::endl;
}