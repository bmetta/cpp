#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include <initializer_list>

class Widget {
public:
  Widget(std::initializer_list<std::string> _names) { 
    names.reserve(_names.size());
    for(auto name: _names)  {
      names.push_back(name);
    }
  }

private:
  std::vector<std::string> names;
};

int main()
{
  Widget w{"Steve", "Paul", "Peter"};

  return 0;
}
