#include <iostream>
using namespace std;

class Base {
public:
  friend void f(Base& b);
  // ...
private:
  virtual void do_f() {
    cout << "Base do_f()" << endl;
  }
};
inline void f(Base& b)
{
  b.do_f();
}
class Derived : public Base {
public:
  // ...
protected:
  void do_f(){  // "Override" the behavior of f(Base& b)
    cout << "Derived do_f()" << endl;
  }
};
void userCode(Base& b)
{
  f(b);
}

int main()
{
  Base b;
  userCode(b);

  Derived d;
  userCode(d);
}
