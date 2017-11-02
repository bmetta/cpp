#include <iostream>
using namespace std;

void f(int* ptr) {
  cout << ptr << endl;
}

template<typename F, typename P>
void logAndCall(F foo, P param) {
  foo(param);
}

int main()
{
  logAndCall(f, 0);       // won't compile
  logAndCall(f, NULL);    // won't compile
  logAndCall(f, nullptr); // works
}
