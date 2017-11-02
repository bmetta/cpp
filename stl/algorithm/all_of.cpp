#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

bool isOdd(int i)
{
  return (i%2);
}

int main()
{
  array<int,8> foo = {3, 5, 7, 9, 11, 13, 17, 20};

  if(all_of(foo.begin(), foo.end(), isOdd))  {
    cout << "All are odd" << endl;
  }
}
