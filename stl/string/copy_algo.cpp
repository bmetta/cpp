// copy algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <vector>       // std::vector
#include <sstream>
#include <iterator>
using namespace std;

int main () {
  int myints[]={10,20,30,40,50,60,70};
//  vector<int> myvector(7);
  vector<string> myvector;
  stringstream ss;

  copy (myints, myints+7, ostream_iterator<int>(ss, " "));
  string res = ss.str();
//  res.erase(res.begin() + res.size() - 1);
  res.pop_back();
  cout << "'" << res << "'" << endl;

//  for (auto it : myvector)
//    cout << it << " ";
//  cout << endl;

  return 0;
}
