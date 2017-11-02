#include <iostream>
using namespace std;

class Test {
 public:
   int x;

   Test()  { x = 100; }
};

int main() {
  Test t;
  int Test::*ptr = &Test::x;
  cout << &t << " " << &(t.x) << " " << &(t.*ptr) << endl;
  cout << t.*ptr << endl;
  t.*ptr = 200;
  cout << t.*ptr << endl;
  cout << t.x << endl;

  return 0;
}
