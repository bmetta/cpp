#include <iostream>
class Y {
public:
  Y();
  void f();
};
Y::Y()      { std::cout << "Initializing Y\n"; }
void Y::f() { std::cout << "Using Y\n"; }

class X {
public:
  X(Y& y);
};
X::X(Y& y) { y.f(); }

class Z {
public:
  Z();
protected:
  Y y_;
  X x_;
};
Z::Z() : x_(y_), y_() { }
int main()
{
  Z z;
  return 0;
}
