#include <iostream>
using namespace std;

string stringRotateByKtimes(string str, int k)
{
  str = str.substr(k, str.length()) + str.substr(0, k);

  return str;
}

int main()
{
  cout << stringRotateByKtimes("helloworld", 3) << endl;
}
