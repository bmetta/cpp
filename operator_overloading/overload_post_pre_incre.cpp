#include <iostream>
using namespace std;

class Point
{
  public:
    int x, y;

    Point() : x(0), y(0) {
    }
    Point(int a, int b) : x(a), y(b) {
    }
    // Pre increment
    Point& operator++() {
      x++;
      y++;
      return (*this);
    }
    // Post increment
    Point operator++(int t) {
      Point temp (*this);
      x++;
      y++;
      return (temp);
    }
    Point& operator=(Point &p) {
      x = p.x;
      y = p.y;
      return (*this);
    }
};
ostream& operator << (ostream &out, const Point &p)  {
  out << p.x << " " << p.y << endl;
  return out;
}

int main()
{
  Point p;
//  cout << ++p;
//  cout << p++;
//
//  cout << p.x << " " << p.y << endl;

  Point q(5, 6);
//  ++p = q;
//  cout << p.x << " " << p.y << endl;
  cout << (p++ = q);
  cout << p.x << " " << p.y << endl;

  return 0;
}
