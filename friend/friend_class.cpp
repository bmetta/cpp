#include <iostream>
using namespace std;

class A
{
private:
  int x;

public:
  A() { x = 10; }
  friend class B;
};

class B
{
public:
  void show(A& a) { cout << a.x << endl; }
};

int main()
{
  A a;
  B b;
  b.show(a);

  return 0;
}
