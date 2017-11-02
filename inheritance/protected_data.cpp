#include <iostream>
#include <iomanip>
using namespace std;

class Base
{
protected:
  int i;
public:
  Base(int i = 0) : i(i) {}
  void display() {
    cout << i << endl;
  }
};

class Derived : public Base
{
public:
  Derived(int i = 1) : Base(i) {}
  void display() {
    cout << i << endl;
  }
};

int main()
{
  Base b;
  b.display();

  Derived d;
  d.display();

  return 0;
}
