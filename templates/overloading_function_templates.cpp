#include <iostream>
using namespace std;

// maximum two ints
inline const int& max(const int& a, const int& b)
{
  cout << "max of two ints: ";
  return (a > b ? a : b);
}

// maximum of any two valuies of any type
template<typename T>
inline const T& max(const T& a, const T& b)
{
  cout << "max of two values of any type: ";
  return (a > b ? a : b);
}

// maximum of three values of any type
template<typename T>
inline const T& max(const T& a, const T& b, const T& c)
{
  cout << "max of three values of any type: ";
  return ::max(::max(a, b), c);
}

int main()
{
  cout << ::max(1, 2) << endl;
  cout << ::max<double>(1, 2) << endl;
  cout << ::max(1.5, 2.5) << endl;
  cout << ::max(1.5, 2.5, 3.5) << endl;
}
