#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
  Base() { cout << "Base ctor" << endl; }
  virtual ~Base() { cout << "Base dtor" << endl; }
  
  virtual void display() { cout << "Base: display" << endl; }
};
class Derived : public Base
{
public:
  Derived() { cout << "Derived ctor" << endl; }
  ~Derived() { cout << "Derived dtor" << endl; }

  void display() { cout << "Derived: display" << endl; }
};

int main()
{
  cout << "*****************" << endl;
  shared_ptr<Base> bp1(new Derived);
//  bp1 = nullptr; // deletes the reference count
  bp1->display();
  bp1.reset();

  cout << "*****************" << endl;
  shared_ptr<Derived> dp1(new Derived);
  bp1 = dp1;
  
  cout << "*****************" << endl;
//  shared_ptr<Base> bp2 = make_shared<Derived>();
  shared_ptr<Base> bp2(make_shared<Derived>());
  cout << "*****************" << endl;
  
  return 0;
}
