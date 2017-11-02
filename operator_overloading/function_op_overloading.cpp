#include <iostream>
using namespace std;

class Test
{
public:
  Test() { cout << "constructor" << endl; }
  ~Test() { cout << "Destructor" << endl; }
  void operator()() { cout << "fun op overloading" << endl; }
  Test t1() { cout << "t1" << endl; }
};

int main()
{
  Test t;
}
