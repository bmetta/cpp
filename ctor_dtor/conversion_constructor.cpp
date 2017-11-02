#include <iostream>
using namespace std;


class Foo1 {
  int x;

public:
  Foo1(int x) : x(x) { cout << "Foo1(int x)" << endl; }
  operator int() {cout << "operator int()" << endl; return x; }
};

int main1() {
  Foo1 a = 42;          // Okay: calls Foo1::Foo1(int) passing 42 as an argument
  Foo1 b(42);           // Okay: calls Foo1::Foo1(int) passing 42 as an argument
  Foo1 c = Foo1(42);    // Okay: calls Foo1::Foo1(int) passing 42 as an argument
  Foo1 d = (Foo1)42;    // Okay: calls Foo1::Foo1(int) passing 42 as an argument
  int e = d;            // Okay: calls Foo1::operator int()
  cout << e << endl;

  return 0;
}


class Foo2 {
  double x;

public:
  Foo2(double x) : x(x)        { std::cout << "Foo2(double)\n"; }
  explicit Foo2(bool x) : x(x) { std::cout << "explicit Foo2(bool)\n"; }
  operator double()            { std::cout << "operator double()\n"; return x; }
  explicit operator bool()     { std::cout << "explicit operator bool()\n"; return x; }
};

int main2() {
  Foo2 a = true;        // Okay: implicitly promotes true to (double)1.0, then calls Foo2::Foo2(double)
  Foo2 b = Foo2(true);  // Okay: explicitly calls Foo2::Foo2(bool)
  double c = b;         // Okay: implicitly calls Foo2::operator double()
  bool d = b;           // Okay: calls Foo2::operator double() and implicitly converts to bool
  cout << c << " " << d << endl;
  if(b) {}              // Okay, explicitly calls Foo2::operator bool()

  return 0;
}


struct Point1 {
  int x,y;

  Point1(int xx = 0, int yy = 0) : x(xx), y(yy) { }
};

void f(Point1 p) { cout << p.x << " " << p.y << endl; }

int main3() {
  Point1 orig;  // create orig with the default value (0,0)
  Point1 p1(2); // create p1 with the default y-coordinate 0
  f(2);         // calls Point1(2,0);

  return 0;
}

struct Point2 {
  int x,y;

  explicit Point2(int xx = 0, int yy = 0) :x(xx), y(yy) { }
};

void f(Point2 p) { cout << p.x << " " << p.y << endl; }

int main() {
  Point2 orig;           // create orig with the default value (0,0)
  Point2 p1(2);          // create p1 with the default y-coordinate 0
                         // that's an explicit call of the constructor
  f(2);                  // attempted implicit conversion
//  Point2 p2 = 2;         // error (attempted implicit conversion)
  Point2 p3 = Point2(2); // ok (explicit conversion)

  return 0;
}
