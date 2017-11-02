#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void parse(vector<string> const &p) {
  vector<vector<int>> res;
  vector<int> t;

  for(auto str: p) {
    t.clear();
    stringstream ss(str);
    copy(istream_iterator<int>(ss), istream_iterator<int>(), \
              back_inserter(t));
    res.push_back(t);
  }
  for(auto t: res) {
    for(auto i: t) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main()
{
  vector<string> p;

  p.push_back("9 2 3");
  p.push_back("4 8 7");

  parse(p);
}
