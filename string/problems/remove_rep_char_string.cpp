#include <iostream>
using namespace std;

string removeRepetitiveChar(string str)
{
  int w = 0, r = 0;
  char ch = '.';

  for(; r < str.length(); r++)
  {
    if(ch != str[r])
    {
      str[w++] = str[r];
      ch = str[r];
    }
  }
  str.resize(w);

  return str;
}

int main()
{
  cout << removeRepetitiveChar("eeeefggkkosss") << endl;
  cout << removeRepetitiveChar("baaccccffffeeee") << endl;
}
