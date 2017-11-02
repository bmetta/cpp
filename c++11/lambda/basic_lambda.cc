#include <iostream>

int main() {
  auto func = []() { std::cout << "lamda function" << std::endl; };
  // [] capture specification, tells compiler to create a lamda function
  // () arg list
  // return value?
  //    default doesnt have a return type
  //    compiler will deduce the return type from the return expression
  //    programer can specify the return value
  // [] () -> int { return 1; }
  func();

  return 0;
}
