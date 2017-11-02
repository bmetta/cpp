#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int isAnagrams(string str1, string str2)
{
  int i;
  map <char, int> map1;
  map <char, int> map2;

  for(i = 0; i < str1.length(); i++)
  {
    if(str1[i] != ' ')
    {
      map1[str1[i]]++;
    }
  }

  for(i = 0; i < str2.length(); i++)
  {
    if(str2[i] != ' ')
    {
      map2[str2[i]]++;
    }
  }

  cout << map1.size() << ", " << map2.size() << endl;
  if(map1.size() != map2.size())
    return 0;

  map <char, int>::iterator it1 = map1.begin();
  map <char, int>::iterator it2 = map2.begin();

  for(; it1 != map1.end() && it2 != map2.end(); it1++, it2++)
  {
    cout << it1->first << ": " << it1->second << endl;
    cout << it2->first << ": " << it2->second << endl;
    if(it1->second != it2->second)
      return 0;
  }

  return 1;
}

/*
int isAnagrams(string str1, string str2)
{
  char *c_str1 = (char *)str1.c_str();
  cout << c_str1 << endl;
  cout << str2 << endl << endl;

  int found;
  for(int i = 0; c_str1[i] != '\0'; i++)
  {
    found = str2.find(c_str1[i]);
    if(found != -1)
    {
      str2 = str2.substr(0, found) + str2.substr(found+1, str2.length());
      cout << str2 << endl;
    }
    else
      return 0;
  }
  return str2.empty();
}
*/

int main()
{
  string str1 = /*"armya"*/"aaca";
  string str2 = /*"mary"*/ "acaa";

  if(isAnagrams(str1, str2))
    cout << "anagrams" << endl;
  else
    cout << "not anagrams" << endl;
}

