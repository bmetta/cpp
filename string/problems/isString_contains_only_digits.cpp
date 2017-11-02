#include <iostream>
#include <stdbool.h>
#include <cstdlib>
using namespace std;

bool isStringContainsOnlyDigits(string str)
{
//  return str.find_first_not_of("0123456789");
  isdigit(str[0]);
  char ch;;
  for(int i = 0; i < str.length(); i++)
  {
    if(!isdigit(str[i]))
      return false;
//    if(isalpha(str[i]))
//      return false;
  }
  return true;
}
int main()
{
  isStringContainsOnlyDigits("012345678") == true  ? cout << "PASS \n" : cout << "FAIL \n";
  isStringContainsOnlyDigits("-012345678") == false  ? cout << "PASS \n" : cout << "FAIL \n";
  isStringContainsOnlyDigits("ABbcdX678") == false ? cout << "PASS \n" : cout << "FAIL \n";
}
