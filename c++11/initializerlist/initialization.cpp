#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Widget {
public:
  // initilization in c++11
  Widget() : data {1, 2, 3, 4, 5} { }

private:
  const int data[5];
};

class Point {
public:
  Point(int x, int y) : i(x), j(y) {}
  Point makePoint() {return {0, 0}; };

private:
  int i, j;
};

class Widget1 {
public:
  explicit Widget1(int x) {}
};

void foo(const std::vector<int> &v) { } 

int main() {
  // initialization in c++98
  int vals[] = {10, 20, 30};
  std::vector<int> v(vals, vals+3);

  // initilization in c++11
  const float *pfl = new const float[4] {1.5, 2.5, 3.5, 4.5};
  const int val1 {5};
  int a[] {1, 2, val1, val1 + 2};
  Point p{10, 20};
  foo({10, 20, 30});

  Widget1 w1(10); // or w1{10};
  Widget1 w2 = (10); // or = {10}; // error

  return 0;
}
