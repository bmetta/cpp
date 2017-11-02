#include <iostream>
#include <iomanip>
using namespace std;

class Test {
private:
  ~Test() { cout << "destructor" << endl; }
  friend void destruct(Test *p) { delete p; }
};

int main() {
  Test *t = new Test;

  destruct(t);

  return 0;
}
