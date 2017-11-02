#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
  std::vector<int> v {};
  
  v.insert(v.begin(), {1, 2, 3});
  for(auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
