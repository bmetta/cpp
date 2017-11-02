#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
  Base() { cout << "Base ctor" << endl; }
  virtual ~Base() { cout << "Base dtor" << endl; }

  virtual void display() { cout << "Base display" << endl; }
};
class Derived : public Base
{
public:
  Derived() { cout << "Derived ctor" << endl; }
  ~Derived() { cout << "Derived dtor" << endl; }

  void display() { cout << "Derived display" << endl; }
};

int main()
{
  Base *bp = new Derived();
  bp->display();
  delete bp;

  return 0;
}
