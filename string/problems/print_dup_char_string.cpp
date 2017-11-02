#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

void printDupes(string str)
{
  unordered_map <char, int> myMap;
  unordered_map <char, int>::iterator it;
//  map <char, int> myMap;
//  map <char, int>::iterator it;
  
  for(int i = 0; i < str.length(); i++)
  {
    if((it = myMap.find(str[i])) != myMap.end())
      it->second++;
    else
      myMap.insert(it, pair<char, int>(str[i], 1));
  }

  for(it = myMap.begin(); it != myMap.end(); it++)
  {
    if(it->second > 1)
    {
      cout << it->first << ": " << it->second << endl;
    }
  }
  cout << endl;
}

int main()
{
  string str;

  printDupes("Programming");
  printDupes("Combination");

  return 0;
}
