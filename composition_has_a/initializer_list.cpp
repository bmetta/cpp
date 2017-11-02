#include <iostream>
using namespace std;

class A
{
 public:
   A(int x)  { this->x = x; }
  
 private:
   int x;
};

class B
{
 public:
   B(int x) : a(x)  { }

 private:
   A a;
};

int main()
{
  B b(10);
}
