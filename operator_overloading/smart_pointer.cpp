#include <iostream>
using namespace std;

class Test
{
private:
  int x;
  int y;
public:
  Test(int i = 0, int j = 0): x(i), y(j) {}
  void display() { cout << x << " " << y << endl;  }
};

template<class T>
class SmartPtr
{
private:
  T* p;
public:
  SmartPtr(T* t = NULL): p(t) {}
  ~SmartPtr() {
    delete p;
    cout << "SmartPtr destructor" << endl;
  }
  T& operator* ()  { return *p; }
  T* operator-> () { return p; }
};

int main()
{
//  SmartPtr<Test> obj(new Test(10, 20));
  SmartPtr<Test> obj = new Test(10, 20);
//  (*obj).display();
  obj->display();

  return 0;
}
