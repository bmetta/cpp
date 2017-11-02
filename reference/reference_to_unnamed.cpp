#include <iostream>
using namespace std;

void foo(const string& str) { cout << str << endl; }
void foo(string& str) { cout << str << endl; }
void foo(const int& x) { cout << x << endl; }

int main()
{
  string s1;
  string& s1ref = s1;   // s1ref "refers" to s1
  string str = "Hello World";
  // Here, we construct an unnamed, temporary string object to call foo.
  // foo's "str" parameter now "refers to" this unnamed object.
  foo(string("Hello World"));
  foo(str);
  foo(10);
}
