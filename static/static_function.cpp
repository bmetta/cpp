#include<iostream>
using namespace std;
 
class A {
  int x;

 public:
  void setX(int i) {x = i;}
  void print() { cout << x << endl; }
};
 
static void foo(A& aa) {
  cout << "in static" << endl;
  aa.setX(100);
}
 
int main()
{
    A a;
    a.setX(10);
    a.print();
    foo(a);
    a.print();

    return 0;
}

