#include <iostream>
using namespace std;

class Test
{
  public:
    int x;

    Test()  {
      cout << "Constructor" << endl;
      x = 10;
    }
    ~Test() {
      cout << "Destructor" << endl;
    }
};
int main()
{
  char memory[sizeof(Test)];
  void *place = memory;

  Test *t = new(place) Test();

  cout << place << " " << t << endl;

  t->~Test();
}
