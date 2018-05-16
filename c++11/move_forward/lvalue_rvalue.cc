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
 *
 * reference: http://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php
 *
 * lvalue
 * rvalue
 * rvalue reference => (&&) binds only to rvalues
 *
 * move => takes an lvalue and converts it into an rvalue
 *
 * rvalue references enable us to distinguish an lvalue from an rvalue
 * C++11 introduces rvalue references which bind only to rvalues
 *
 * C++0x use lvalue reference to bind temporary object
 * const int& val = getValue();
 * getValue() is an rvalue
 * 
 * int& value => takes only lvalue
 * const int& value => takes lvalue or rvalue
 * int&& value => takes only rvalue reference
 *
 */
string getName() {
  return "Alex";
}

#if 0
int main() {
  //string& name2 = getName(); // Error in C++03 and C++11
  const string& name1 = getName(); // ok in C++03 and C++11
  string&& name4 = getName(); // new feature in C++11
  
  // C++11
  string str = "Hello";
  //string&& name5 = str; // cannot bind lvalue to rvalue
  string&& name6 = move(str); // move converts lvalue to rvalue

  return 0;
}
#endif

#if 1
void printReference(const string& str) {
  //str = "name can not be changed";
  cout << "const lvalue: " << str << endl;
}

///*
void printReference(string&& str) {
  str = "name can be changed";
  cout << "rvalue reference: " << str << endl;
}
//*/
int main() {
  string me("alex");
  printReference(me);
  printReference(getName());
}
#endif
