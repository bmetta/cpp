#include<iostream>
using namespace std;
 
class Base {
  public:
    virtual void fun1() { cout << "Base Fun1" << endl; }
    virtual void fun2() { cout << "Base Fun2" << endl; }
    void fun3() { cout << "Base Fun3" << endl; }
};

class Derived: public Base {
  public:
    void fun1() { 
      cout << "Derived Fun1" << endl; 
//      Base::fun1();
    }
//    void fun2() { cout << "Derived Fun2" << endl; }
    virtual void fun3() { cout << "Derived Fun3" << endl; }
};

int main()
{
//  Base *ptr1 = new Base;
//  ptr1->fun1();
//  ptr1->fun2();
//  ptr1->fun3();

  Base *ptr2 = new Derived;
  ptr2->fun1();
  ptr2->fun2();
  ptr2->fun3();

//  Derived *ptr3 = new Derived;
//  ptr3->fun1();
//  ptr3->fun2();
//  ptr3->fun3();

  return 0;
}
