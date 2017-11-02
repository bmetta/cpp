#include <iostream>
#include <iomanip>
using namespace std;

class Base {
private:
  int i;
protected:
  void baseDisplay() {
    cout << "Base Display " << i << endl;
  }
public:
  Base(int i = 0) : i(i) {}
};

class Derived : private Base {
public:
  Derived(int i = 1) : Base(i) {}
  void display() {
    baseDisplay();
  }
  using Base::baseDisplay; // this could be either protected or public
};

int main()
{
  Derived d;
//  d.display();
  d.baseDisplay();

  return 0;
}
