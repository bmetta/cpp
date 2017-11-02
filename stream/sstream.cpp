#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
using namespace std;

int main () {

  string stringvalues = "125,320,512,750,333";
  istringstream iss (stringvalues);

  int val;
  char ch;
  while(iss >> val)
  {
    iss >> ch;
    cout << val << endl;;
  }

  return 0;
}
