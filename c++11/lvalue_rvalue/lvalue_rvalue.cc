#include <iostream>
using namespace std;

/*
 * lvalue => It provides a (semi) permanent piece of memory
 * eg 1: 
 *  int a; a = 1;
 *
 * eg 2: 
 *  int x;
 *  int& getRef() { return x; }
 *  getRef() = 4;
 *
 * rvalue => An expression is rvalue if its results in a temporary object. it refers to a temporary object
 * eg 1:
 *  int x;
 *  int getVal() { return x; }
 *  getVal();
 *
 * eg 2:
 *  string getName() { return "Alex"; }
 *  string name = getName();
 *
 * C++11 rvalue reference => its a reference that will bind only to a temporary object
 *        allows to bind to a mutable reference to an rvalue
 *        rvalue reference is perfect for detecting if a value is temporary object or not
 */
string getName() {
  return "Alex";
}

#if 0
int main() {
  // C++03
  const string& name1 = getName(); // ok
  cout << name1 << endl;
  string& name2 = getName(); // not ok

  //C++11
  const string&& name3 = getName(); // ok
  cout << name3 << endl;

  string&& name4 = getName(); // ok
  cout << name4 << endl;
  
  return 0;
}
#endif

void printReference(const string& str) {
  cout << "const lvalue: " << str << endl;
}

void printReference(string&& str) {
  cout << "rvalue reference: " << str << endl;
}

int main() {
  string me("alex");
  printReference(me);
  printReference(getName());
}
