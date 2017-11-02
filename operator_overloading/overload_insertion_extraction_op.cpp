#include <iostream>
using namespace std;

class Test
{
private:
  int x;
  int y;

public:
  Test(int i = 0, int j = 0) : x(i), y(j) {}
  friend ostream& operator<< (ostream& out, Test& obj);
};

ostream& operator<< (ostream& out, Test& obj) {
  out << obj.x << " " << obj.y << endl;
  return out;
}

int main()
{
  Test t1(10, 20), t2(30, 40);
  cout << t1 << t2;
}
