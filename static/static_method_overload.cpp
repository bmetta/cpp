#include <iostream>
using namespace std;

class Test {
  public:
    static int x;

  void static static_method()  {
    cout << "static method" << endl;
  }
  void static static_method(int x)  {
    cout << "static method int" << endl;
  }
};

int Test::x = 10;

int main()
{
  Test::static_method();
  Test::static_method(10);
}
