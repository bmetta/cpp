#include <iostream>
using namespace std;

class AE 
{
  public:
    static const int c6 = 7;
    static const int c7 = 31;
};

const int AE::c7;   // definition
int f()
{
  const int* p1 = &AE::c6;    // error: c6 not an lvalue
  const int* p2 = &AE::c7;    // ok

  cout << *p2 << endl;
}

int main()
{
  f();
  return 0;
}
