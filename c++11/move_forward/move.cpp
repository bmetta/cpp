#include <iostream>
#include <utility>
#include <string>
using namespace std;

/**
 * move as rvalue
 *
 * template <class T>
 * typename remove_reference<T>::type&& move (T&& arg) noexcept;
 *
 * The function returns the same as:
 *    static_cast<remove_reference<decltype(arg)>::type&&>(arg)
 */
int main()
{
  string foo = "foo";
  string bar;

  cout << "foo: " << foo << "\n";
  cout << "bar: " << bar << "\n\n";

  cout << "moving from foo to bar" << "\n";
  bar = std::move(foo);

  cout << "foo: " << foo << "\n";
  cout << "bar: " << bar << "\n";

  return 0;
}
