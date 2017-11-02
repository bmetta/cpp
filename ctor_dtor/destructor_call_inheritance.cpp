#include <iostream>
using namespace std;

class Member {
public:
  Member() { cout << "Member ctor" << endl; }
  ~Member() { cout << "Member dtor" << endl; }
};

class Base {
public:
  Base() { cout << "Base ctor" << endl; }
  virtual ~Base() { cout << "Base dtor" << endl; }
};

class Derived : public Base {
public:
  Derived() { cout << "Derived ctor" << endl; }
  ~Derived() { 
    cout << "Derived dtor" << endl; 
    // Compiler automagically calls x_.~Member()
    // Compiler automagically calls Base::~Base()
  }

private:
  Member x_;
};

int main() {
  Derived d;
}
