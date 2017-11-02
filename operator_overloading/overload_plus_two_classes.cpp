#include <iostream>
using namespace std;

class A
{
private:
  int x1;
  int y1;

public:
  A(int i = 0, int j = 0) : x1(i), y1(j) {}
//  A& operator+(B& b) {
//    x1 += b.x2;
//    y1 += b.y2;
//  }
  void display() { cout << x1 << " " << y1 << endl;}
  friend class B;
};

class B
{
private:
  int x2;
  int y2;

public:
  B(int i = 0, int j = 0) : x2(i), y2(j) {}
//  friend class A;
  B& operator+(A& a) {
    x2 += a.x1;
    y2 += a.y1;
  }
};

int main()
{
  A a(1, 2);
  B b(3, 4);

  B res = a + b;
//  res.display();

  return 0;
}
