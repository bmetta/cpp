// string::find_first_not_of
#include <iostream>       // std::cout
#include <string>         // std::string
#include <cstddef>        // std::size_t

int main ()
{
  std::string str1 ("banana");
  std::string str2 ("banaba");

  int ret = str1.compare(str2);

  if(ret == 0)
    std::cout << "Eqaul" << '\n';
  else if(ret < 0)
    std::cout << "Shorter" << '\n';
  else if(ret > 0)
    std::cout << "Greater" << '\n';

  return 0;
}
