#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main()
{
  string foo = "foo";
  string bar;

  cout << "foo: " << foo << endl;
  cout << "bar: " << bar << endl;

  bar = move(foo);

  cout << "foo: " << foo << endl;
  cout << "bar: " << bar << endl;

  return 0;
}
