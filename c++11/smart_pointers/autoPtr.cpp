#include <memory>
#include <iostream>
using namespace std;

class T
{
public:
  void DoSomething() { cout << "do something" << endl; }
};

int main()
{
  auto_ptr<T> pt1( new T );
  auto_ptr<T> pt2;

  pt2 = pt1;  // now pt2 owns the pointer, and
              // pt1 does not

  pt1->DoSomething();
              // error! following a null pointer
}
