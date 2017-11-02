/* static initialization order fiasco */
#include <iostream>
using namespace std;

struct Bar {
  Bar () {
    cout << "Bar::Bar()\n";
  }
  void f () {
    cout << "Bar::f()\n";
  }
};
struct Foo {
  Foo () {
//    bar_.f ();
    bar().f();
  }
//  static Bar bar_;
/*
  Bar& bar()  {
    static Bar *b = new Bar();
    return *b;
  }
*/
  Bar& bar()  {
    static Bar b;
    return b;
  }

};

Foo f;
//Bar Foo::bar_;

int main () 
{
}
