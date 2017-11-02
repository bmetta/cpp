#include <iostream>
#include <map>
using namespace std;

void displayCharOccurances(const string &str) {
  multimap<char, int> posMap;
  
  int pos = 1;
  for(auto ch : str) {
    if(ch != ' ') {
      posMap.insert(make_pair(ch, pos));
      pos++;
    }
  }

  for(auto pos : posMap) {
    cout << pos.first << " " << pos.second << endl;
  }

  cout << "----" << endl;
//  pair<multimap<char, int>::iterator, multimap<char, int>::iterator> range = posMap.equal_range('t');
//  multimap<char, int>::iterator it;
  auto range = posMap.equal_range('i');
  for(auto it = range.first; it != range.second; ++it) {
    cout << it->first << " " << it->second << endl;
  }
  cout << "----" << endl;
}

int main() {
  const string str = { "this is it" };
  displayCharOccurances(str);

  return 0;
}
