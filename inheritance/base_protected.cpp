#include <iostream>
using namespace std;

class Base {
  protected:
    int x;

  public:
    Base() {
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
    Derived() { 
      cout << "Derived\n"; 
    }
    ~Derived() { 
      cout << "~Derived " << endl; 
    }
    void set(int i, int j)  {
      x = i;
      y = j;
    }
};

class User  {
  private:
    Base b;

  public:
    User()  {
      cout << "User" << endl;
    }
    ~User()  {
      cout << "~User" << endl;
    }
    set() {
      b.x = 10;
    }
};

int main() 
{
  Derived d;
  d.set(100, 200);

  User u;
  u.set();
}
