// string::find_last_not_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

int main ()
{
  std::string str ("Please, erase trailing white-spaces   \n");
  std::string whitespaces (" \t\f\v\n\r");

  for(int i = 0; i < str.length(); i++)
    std::cout << i << " " << str.at(i) << "\n";
  std::cout << "\n";

  std::cout << "Length: " << str.length() << "\n";
  std::size_t found = str.find_last_not_of(whitespaces);
  std::cout << "found: " << found << "\n";
  if (found!=std::string::npos)
    str.erase(found+1);
  else
    str.clear();            // str is all whitespace

  std::cout << "Length: " << str.length() << "\n";
  std::cout << '[' << str << "]\n";

  return 0;
}
