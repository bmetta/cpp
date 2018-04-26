#include <utility>
#include <iostream>
using namespace std;

/**
 * lvalue (1)
 *  template <class T>
 *  T&& forward(typename remove_reference<T>::type& arg) noexcept;
 *
 * rvalue (2)
 *  template <class T>
 *  T&& forward(typename remove_reference<T>::type&& arg) noexcept;
 *
 *  forward argument
 *    returns an rvalue reference to arg if arg is not an lvalue reference
 *    returns arg without modifying its type of arg is an lvalue reference
 */

// function with lvalue and rvalue reference overloads
void overloaded(const int& x) { cout << "[lvalue]"; }
void overloaded(int&& x)      { cout << "[rvalue]"; }

// function template taking rvalue reference to deduced type
template <class T>
void fun(T&& x) {
  overloaded(x);              // always an lvalue
  overloaded(forward<T>(x));  // rvalue if argument is rvalue
}

int main() {
  int i = 10;

  cout << "calling fun with lvalue: ";
  fun(i);
  cout << endl;

  cout << "calling fun with rvalue: ";
  fun(0);
  cout << endl;
}
