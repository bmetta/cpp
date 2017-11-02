#include <iostream>
using namespace std;

class A;
class B
{
public:
  void show(A& a);
};

class A
{
private:
  int x;

public:
  A() { x = 10; }
  friend void B::show(A& a);
};

void B::show(A& a)
{ 
  cout << a.x << endl; 
}

int main()
{
  A a;
  B b;
  b.show(a);

  return 0;
}
