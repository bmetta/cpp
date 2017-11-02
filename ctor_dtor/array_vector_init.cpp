#include <vector>
using namespace std;

class Fred {
public:
//  Fred();
  Fred(int i, int j) {}      // Assume there is no default constructor
  // ...
};

int main()
{
//  Fred a[10];              // ERROR: Fred doesn't have a default constructor
//  Fred *f = new Fred[10];  // ERROR: Fred doesn't have a default constructor

//  Fred a[5] = {Fred(1, 2), Fred(1, 2), Fred(1, 2), Fred(1, 2), Fred(1, 2)};
  vector<Fred> a(10, Fred(1, 2));

  return 0;
}
