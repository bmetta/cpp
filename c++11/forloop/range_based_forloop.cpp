#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v;
  
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  for(auto i : v) i = -i;

  for(auto &i : v) cout << i << endl;
}
