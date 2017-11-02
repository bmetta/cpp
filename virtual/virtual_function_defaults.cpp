#include<iostream>
using namespace std;
 
class Base {
  public:
    /* default arg do not participate in function signature. so singature of
     * fun in Base and derived are cosidered same, hence the fun() of base class
     * overridden.
     * default value is used at compile time.
     * compiler sees the arg missing while calling fun, so compiler substitutes
     * default value
     */
    virtual void fun(int i = 0) { cout << "Base Fun i: " << i << endl; }
};

class Derived1: public Base {
  public:
    void fun(int i = 10) { cout << "Derived Fun i: " << i << endl; }
};

class Derived2: public Derived1 {
  public:
    void fun(int i = 20) { cout << "Derived Fun i: " << i << endl; }
};

int main()
{
  Base *b1 = new Derived1;
  b1->fun();

  Derived1 *d1 = new Derived1;
  d1->fun();

  Derived1 *d2 = new Derived2;
  d2->fun();

  return 0;
}
