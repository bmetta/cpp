#include <iostream>
using namespace std;

template<typename T>
inline T const& Max(T const& a, T const& b)
{
  return (a > b ? a : b);
}

int main()
{
  cout << "max(4, 5)    : " << Max(4, 5) << endl;
  cout << "max(4.1, 3.9): " << Max(4.1, 3.9) << endl;
  cout << "max(4, 3.9)  : " << Max<double>(4, 3.9) << endl;

  return 0;
}
