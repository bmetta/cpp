#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include <initializer_list>

class Widget {
public:
  Widget(double d1, double d2) { 
    std::cout << "param constructor" << std::endl;
  }

  Widget(std::initializer_list<double> data) {
    std::cout << "initializer_list constructor" << std::endl;
  }

private:
  std::vector<double> data;
};

int main()
{
  Widget w1(2.5, 3.5);
  // When resolving constructor calls, 
  // std::initializer_list parameters are 
  // preferred for brace-delimited arguments:
  Widget w2{2.5, 3.5};

  return 0;
}
