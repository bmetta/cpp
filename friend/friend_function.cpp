#include <iostream>
using namespace std;

class A
{
private:
  int x;

public:
  A() { x = 10; }
  friend void show(A& a);
};

void show(A& a)
{ 
  cout << a.x << endl; 
}

int main()
{
  A a;
  show(a);

  return 0;
}
