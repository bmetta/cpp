#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

template<typename T>
T fun(T a)
{
  cout << "a: " << a << endl;
  return a;
}

class Test {};

int main()
{
  auto x = 10;
  auto a = fun(x);

  cout << "type of a: " << typeid(a).name() << endl;
  cout << "type of class : " << typeid(Test).name() << endl;

  return 0;
}
