#include<iostream>
using namespace std;

class Point
{
public:
	int x;

	Point(int i)  {
		x = i;
    cout << "constructor " << this << endl;
	}
};

int main() {
	Point t = 20;
  cout << &t << " " << t.x << endl;
	t = 30; // conversion constructor will be call here
  cout << &t << " " << t.x << endl;

	return 0;
}
/*
class Point
{
private:
	int x, y;
public:
	Point(int i = 0, int j = 0) {
		x = i; y = j;
	}
	void print() {
		cout << endl << " x = " << x << ", y = " << y;
	}
};

int main() {
	Point t(20, 20);
	t.print();
	t = 30; // Member x of t becomes 30
	t.print();
	return 0;
}
*/
