#include <iostream>
using namespace std;

void h(void l()) 
{
  cout << "in h()" << endl;
  cout << "calling call back" << endl;
  l();
}

void f(void k()) 
{
  cout << "in f()" << endl;
  cout << "calling call back" << endl;
//  k();
//  (*k)();
  h(k);
}

void g() 
{
  cout << "in g()" << endl;
}

int main()
{
  f(g);
  return 0;
}
