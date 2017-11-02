#include <iostream>
using namespace std;

class Base {
  public:
    Base(int i = 0) : x(i) { }

    Base& operator=(Base &obj)  {
      cout << "Base assignment" << endl;
      if(this != &obj) {
        x = obj.x;
      }
      return *this;
    }

    void display() {
      cout << x << endl;
    }

  private:
    int x;
};

class Derived : public Base {
  public:
    Derived(int i = 0, int j = 0) : y(j), Base(i) { }

    Derived& operator=(Derived &obj) {
      cout << "Derived assignment" << endl;
      if(this != &obj) {
        static_cast<Base &>(*this) = obj;
        y = obj.y;
      }
      return *this;
    }

    void display() {
      Base::display();
      cout << y << endl;
    }

  private:
    int y;
};

int main() {
  Base b1(10), b2(20);
  b1.display();
  b2.display();
  cout << "---------------" << endl;

  b1 = b2;
  b1.display();
  cout << "---------------" << endl;

  Derived d1(100, 200), d2;
  d1.display();
  cout << "---------------" << endl;

  d2 = d1;
  d2.display();
}
