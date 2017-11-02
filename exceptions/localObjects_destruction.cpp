#include <iostream>
using namespace std;

class A {
  public:
    A()  { cout << "constructor" << endl; }
    ~A() { cout << "destructor" << endl; }
};

int main(int argc, const char * argv[]) {
  try {
    A a;
    throw 32;
  } catch(int a) {
    cout << a;
  }
}
