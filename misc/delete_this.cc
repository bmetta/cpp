#include<iostream>
using namespace std;
 
class Test {
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  { delete this; cout << "inside\n\n";}
  void print() { cout << "x = " << x << " y = " << y << endl; }

private:
  int x;
  int y;

};
 
int main()
{
  Test obj;
  obj.destroy();
  cout << "After del\n\n";
  obj.print();
  return 0;
}
