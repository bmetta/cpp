#include <iostream>
#include <vector>
#include <algorithm>
//#include <iterator>
using namespace std;

bool comp(int i, int j)
{
  return i > j;
}

int main()
{
  int val;
  vector<int> v;

  while(cin >> val) v.push_back(val);
  if(! cin.eof()) {
    cin.clear();
    string str;
    cin >> str;
    if(str != "end") {
      cout << "format error" << endl;
      return 1;
    }
  }

  copy(v.begin(), v.end(), ostream_iterator<int> (cout, " ")); cout << endl;

  sort(v.begin(), v.end(), comp);
  copy(v.begin(), v.end(), ostream_iterator<int> (cout, " ")); cout << endl;

//  reverse(v.begin(), v.end());
//  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout << endl;

  return 0;
}
