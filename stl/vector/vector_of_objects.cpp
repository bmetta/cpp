#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Test
{
  public:
    int x;
    int y;

    Test()  {
      x = 0;
      y = 0;
    }
    Test(int i, int j) :x(i), y(j)  {
    }
};

ostream& operator << (ostream &out, const Test &t) {
  out << t.x << " " << t.y;
  return out;
}

int main()
{
//  vector<Test> v(5, Test());
  vector<Test> v(5, Test(10, 20));

  copy(v.begin(), v.end(), ostream_iterator<Test> (cout, "\n"));
}
