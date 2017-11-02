#include <iostream>
using namespace std;

class Base  {};
class Derived : public Base  {};

int main()
{
  Derived d;
  try {
    throw d;
  } catch (Derived d) {
    cout << "In derived class catch" << endl;
  } catch (Base b) {
    cout << "In base class catch" << endl;
  }
}
