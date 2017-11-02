#include <iostream>
using namespace std;

class Foo {
private:
  int x, y;

public:
  Foo(char x) : x(x) { *this = Foo(20, 30); }
//  Foo(char x) : Foo(20, 30) { } // C++11 delegating constructor
  Foo(char x, int y) : x(x), y(y) {}
  void display() { cout << x << " " << y << endl; }
};

int main() {
  Foo f(10);
  f.display();
}
