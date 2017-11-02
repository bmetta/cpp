#include <iostream>
using namespace std;

class Base {
public:
  int x;

  Base(int x) :x (x)  {}
  Base(const Base&) { cout << "Base copy ctor\n"; }
  Base& operator=(const Base &b) {
    cout << "Base assignment op \n"; 
    x = b.x;
  }
};

class Derived : public Base
{
public:
  int additional_;

  Derived(int x, int y) : Base(x), additional_(y) {}
  Derived(const Derived& d) : Base(d), additional_(d.additional_) {
    cout << "Derived copy ctor\n";
  }
/*  
  Derived& operator=(const Derived& d)
  {
    cout << "Derived assignment op\n";
    Base::operator=(d);
    additional_ = d.additional_;
    return *this;
  }
*/
  /* If we dont define our own assignment operator then compiler 
   * will generate the following way */
/*  
  Derived& operator = (const Derived& rhs)
  {
    Base1::operator =(rhs);
    ...
    Basen::operator =(rhs);
    member1 = rhs.member1;
    ...
    membern = rhs.membern; 
  }
*/
};

int main()
{
  Derived d1(10, 20), d2(30, 40);
  cout << d1.x << " " << d1.additional_ << endl;
  cout << d2.x << " " << d2.additional_ << endl;
  d2 = d1;
  cout << d2.x << " " << d2.additional_ << endl;
}
