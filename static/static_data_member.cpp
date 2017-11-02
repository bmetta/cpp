#include <iostream>
using namespace std;

class A
{
public:
  A() { cout << "A's constructor called" << endl;  }
};

class B
{
  static A a;
public:
  B() { cout << "B's constructor called" << endl;  }
  static A getA() { return a; }
};

A B::a;

int main()
{
  B b;
  A a = B::getA();

  return 0;
}
