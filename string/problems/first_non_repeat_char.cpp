#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

/*
void printMap(unordered_map<char, int> my_map)
{
  unordered_map <char, int>::iterator it = my_map.begin();

  for(; it != my_map.end(); it++)
    cout << it->first << " ";
  cout << endl;
}

int firstNonRepeatChar(string str)
{
  int i;
  unordered_map <char, int> myMap;
  unordered_map <char, int>::iterator it;

//  for(i = str.length() - 1; i >= 0; i--)
  for(i = 0; i < str.length(); i++)
  {
    cout << "  " << str[i] << endl;
    it = myMap.find(str[i]);
    if(it != myMap.end())
      it->second++;
    else
      myMap.insert(it, pair<char, int>(str[i], 1));
    printMap(myMap);
  }

  it = myMap.begin();
  for(; it != myMap.end(); it++)
  {
    if(it->second == 1)
    {
      cout << it->first;
      return it->first;
    }
  }
  return ('@');
}
*/

void printSet(set<int> my_set)
{
  set <int>::iterator it = my_set.begin();

  for(; it != my_set.end(); it++)
    cout << *it << " ";
  cout << endl;
}
int firstNonRepeatChar(string str)
{
  int i, count;
  set <int> mySet;
  set <int>::iterator it;

  for(i = 0; i < str.length(); i++)
  {
    it = mySet.find(str[i]);
    if(it != mySet.end())
    {
      count = *it;
      mySet.erase(it);
      mySet.insert(count + 1);
      cout << "count" << count << "  " << endl;
    }
    else
      mySet.insert(1);

//    printSet(mySet);
  }

//  it = mySet.begin();
//  for(; it != mySet.end(); it++)
//  {
//    if(it->second == 1)
//    {
//      cout << it->first;
//      return it->first;
//    }
//  }
  return ('@');
}

int main()
{
  firstNonRepeatChar("abcdefghija") == 'b' ? (cout << "  PASS\n\n") : (cout << "  FAIL\n\n");
  firstNonRepeatChar("hello") == 'h'       ? (cout << "  PASS\n\n") : (cout << "  FAIL\n\n");
  firstNonRepeatChar("Java") == 'J'        ? (cout << "  PASS\n\n") : (cout << "  FAIL\n\n");
  firstNonRepeatChar("simplest") == 'i'    ? (cout << "  PASS\n\n") : (cout << "  FAIL\n\n");
}

