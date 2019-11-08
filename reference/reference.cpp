#include <iostream>
using namespace std;

int main()
{
  int x = 10;
  int &ref = x;
  ref = 20;
  cout << x << "\t" << ref << endl;

  int* ptr = &x;
  int* &refPtr = ptr;
  *refPtr = 30;
  cout << *ptr << "\t" << *refPtr << endl;
  x = 40;
  cout << *ptr << "\t" << *refPtr << endl;

  const int &ref_c = 10; // unnamed reference
  cout << ref_c << endl;

  return 0;
}
