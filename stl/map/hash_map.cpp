#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, string> buildMap()
{
  map<int, string> myMap;
  pair<map<int,string>::iterator, bool> ret;

  ret = myMap.insert(pair<int, string>(1, "Peter"));
  if(ret.second == false) {
    cout << ret.first->first << " " << ret.first->second << " Exists!" << endl;
  }
  ret = myMap.insert(pair<int, string>(2, "George"));
  if(ret.second == false) {
    cout << ret.first->first << " " << ret.first->second << " Exists!" << endl;
  }
  ret = myMap.insert(pair<int, string>(2, "Jhon"));
  if(ret.second == false) {
    cout << ret.first->first << " " << ret.first->second << " Exists!" << endl;
  }

  return myMap;
}

int main()
{
  map<int, string> myMap = buildMap();
  map<int, string>::iterator it;

  for(it = myMap.begin(); it != myMap.end(); ++it)  {
    cout << it->first <<" " << it->second << endl;
  }

  return 0;
}
