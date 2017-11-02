#include <iostream>
#include "Fred.h"
using namespace std;

int main()
{
  Fred f;
  cout << f.val << endl;
  cout << Fred::max1 << endl;
  cout << Fred::max2 << endl;
  cout << Fred::min << endl;
}
