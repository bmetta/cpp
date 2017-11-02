#include<iostream>
using namespace std;
  
class Base
{
private:
//  Base& operator=(Base& b) {cout << "Base assignment operator" << endl;}
public:
  Base() {cout << "Base constructor" << endl;}
  Base& operator=(Base& b) {cout << "Base assignment operator" << endl;}
};
  
class Derived: public Base
{
public:
  Derived() {cout << "Derived constructor" << endl;}
  Derived& operator=(Derived& b) {cout << "Derived assignment operator" << endl;}
};

int main()
{
  Derived d1, d2;
  d1 = d2;

  Base *b1 = &d1;
  Base *b2 = &d2;
  *b1 = *b2;

  return 0;
}
