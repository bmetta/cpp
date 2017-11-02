#include <iostream>
#include <iomanip>
#include <vector>

int main() {
  std::vector<int> v {10, 3, 11, 1, 5};

  std::sort(v.begin(), v.end(), 
            [](const int& i1, const int& i2) { return i1 < i2; });
  for_each(v.begin(), v.end(), [](const int& i) { std::cout << i << " "; } );
  std::cout << std::endl;

  return 0;
}
