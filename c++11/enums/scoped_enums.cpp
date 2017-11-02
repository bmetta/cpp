#include <iostream>
#include <iomanip>
using namespace std;

enum class Elevation: char {low, high}; // underlying type = char
enum class Voltage {low, high};        // underlying type default to int

int main()
{
  Elevation e1 = low; // error; values scoped to enum type
  Elevation e2 = Elevation::low; // values scoped to enum type
  
  int x = Voltage::high; // error; No implicit conversion to int

  return 0;
}
