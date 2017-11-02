// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double>
              myrecipe,
              mypantry = {{"milk",2.0},{"flour",1.5}};

  std::pair<std::string,double> myshopping ("baking powder",0.3);

  myrecipe.insert (myshopping);                        // copy insertion
  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;
  std::cout << std::endl;
  myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;
  std::cout << std::endl;
  myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;
  std::cout << std::endl;
  myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}
