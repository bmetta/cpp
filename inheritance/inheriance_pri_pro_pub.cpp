#include <iostream>
using namespace std;

class Base
{
};

class Derived: private Base // wont work
class Derived: protected Base // wont work
class Derived: public Base
{
};

int main()
{
  Base *b = new Derived();
}
