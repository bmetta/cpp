#include <iostream>
using namespace std;

class CustomizedInt
{
  private:
    int data;
  public:
    CustomizedInt() {
      data = 10;
    }
    CustomizedInt(int input)  {
      data = input;
    }
    operator unsigned long int () const {
      unsigned long int output;
      output = (unsigned long int)data;
      return output;
    }
    operator int()  const {
      return data;
    }
};

int main()
{
  CustomizedInt x;
  unsigned long int y = x;
  int k = x;

  cout << y << endl;
  cout << k << endl;

  return 0;
}

/*
class B;
class A
{
	int i;
public:
	A(int ii = 0) : i(ii) {cout << "A Constructor" << endl;}
//  A(B &obj)  { i = 10; }

	void show() { cout << i << endl; }
};

class B
{
	int x;
public:
	B(int xx) : x(xx) {cout << "B Constructor" << endl;}
	operator A() const { 
    return A(x); 
  }
};

void g(A a)
{
	a.show();
}

int main()
{
	B b(10);
  A a = b;
  a.show();
	g(b);
	g(20);
	return 0;
}
*/
