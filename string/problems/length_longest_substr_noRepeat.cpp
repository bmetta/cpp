#include <iostream>
#include <map>
using namespace std;

int longestUniqueSubsttr(string str)
{
  int max_len;
  int start;
  map<char,int> map_visited;
  map<char,int>::iterator prev_index;
//  map<char,int>::iterator it;

  start = 0;
  max_len = 1;
  map_visited.insert(pair<char,int>(str[0],0));
//  cout << "map contains:\n";
//  for (it=map_visited.begin(); it!=map_visited.end(); ++it)
//    cout << it->first << " => " << it->second << endl;

  for (int i = 1; i < str.length(); i++)
  {
    prev_index = map_visited.find(str[i]);
    if (prev_index != map_visited.end() && prev_index->second >= start)
    {
      if(max_len < (i - start))
        max_len = i - start;
      start = prev_index->second + 1;
      map_visited.erase(prev_index);
//      cout << "Erased: " << prev_index->second << " " << prev_index->second << endl;
    }
    map_visited.insert(pair<char,int>(str[i], i));
//    cout << "map contains:\n";
//    for (it=map_visited.begin(); it!=map_visited.end(); ++it)
//      cout << it->first << " => " << it->second << endl;
//    cout << "Inserted: " << i << " " << str[i]<< endl;
  }
//  cout << "Lenght: " << max_len << endl;

  return max_len;
}

/* Driver program to test above function */
int main()
{
  (6 == longestUniqueSubsttr("ABDEFGABEF"))    ? cout << "PASS\n" : cout << "FAIL\n";
  (7 == longestUniqueSubsttr("GEEKSFORGEEKS")) ? cout << "PASS\n" : cout << "FAIL\n";

  return 0;
}
