#include <iostream>
using namespace std;

class Base {
  protected:
    int x;

  public:
    Base(int i) : x(i) {
      cout << "Base\n"; 
    }
    virtual ~Base() {
      cout << "~Base " << endl; 
    }
};

class Derived : public Base {
  private:
    int y;
  
  public:
    Derived(int i, int j) : y(j), Base(i)  { 
      cout << "Derived\n"; 
    }
    ~Derived() { 
      cout << "~Derived " << endl; 
    }
    friend void foo(Derived &); // can access protected members of Base class
};

void foo(Derived &d)  {
  cout << d.x << " " << d.y << endl;
}

int main() 
{
  Base b(9);
  Derived d(10, 20);
  foo(d);
}
