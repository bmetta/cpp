#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  vector<int> apple(3, 0);
  vector<int> pears(3, 0);
  vector<int> mango(3, 0);
  vector<int> fruit;
  map<string, vector<int>> str_map_vec;

  str_map_vec.insert(pair<string, vector<int>>("Apple", apple));
  str_map_vec.insert(pair<string, vector<int>>("Pears", pears));
  str_map_vec.insert(pair<string, vector<int>>("Mango", mango));

  str_map_vec["Apple"][0] = 10;

  for(auto it : str_map_vec) {
    cout << it.first << " ";
    for(auto val : it.second) {
      cout << val << " ";
    }
    cout << endl;
  }
}
