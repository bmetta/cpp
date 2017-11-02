#include <iostream>
#include <iomanip>
using namespace std;

void func(int x)
{
  cout << "int: " << x << endl;
}

void func(int *x)
{
  cout << "int* : " << x << endl;
}

template<typename F, typename P>
void logAndCall(F foo, P param) 
{
  foo(param);
}

int main()
{
//  logAndCall(func, 0);
  logAndCall(func, nullptr);

  return 0;
}
