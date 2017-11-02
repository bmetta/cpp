#include <iostream>
#include <unordered_map>
using namespace std;

string removeDupes(string str)
{
  int w = 0, r = 0;
  unordered_map <char, int> myMap;
  unordered_map <char, int>::iterator it;

  for(; r < str.length(); r++)
  {
    if((it = myMap.find(str[r])) == myMap.end())
    {
      str[w++] = str[r];
      myMap.insert(it, pair<char, int>(str[r], 1));
    }
  }
  str.resize(w);

  return str;
}

int main()
{
  cout << removeDupes("geeksforgeeks") << endl;
  cout << removeDupes("babacfcececfefg") << endl;
  cout << removeDupes("bananas") << endl;
}
