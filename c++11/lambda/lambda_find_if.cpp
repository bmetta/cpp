#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
  std::vector<int> v {10, 20, 9, 40, 1};

  auto it = std::find_if(v.cbegin(), v.cend(), 
                         [](int i){ return i > 0 && i < 10; });
  std::cout << *it << std::endl;

 // Essentially generates
  /*
  class MagicType {
  public:
    bool operator()(int i) const {
      return i > 0 && i < 10;
    }
  };

  auto it1 = std::find_if(v.cbegin(), v.cend(), MagicType());
  std::cout << *it1 << std::endl;
  */
  return 0;
}
