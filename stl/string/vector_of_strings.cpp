#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

int main()
{
  string str[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"};
  vector<string> vec(str, str+4);
  vector<string> res;
  map<string, vector<int>> str_vec_map;
  vector<int> map_val(3, 0);

  for(auto s : vec) {
    vector<string> temp;
    stringstream ss(s);
    copy(istream_iterator<string>(ss), istream_iterator<string>(), 
          back_inserter(temp));

    for(int i = 0; i < temp.size(); i++) {
      if(str_vec_map.end() == str_vec_map.find(temp[i]))  {
        str_vec_map.insert(pair<string, vector<int>>(temp[i], map_val));
      }
      str_vec_map[temp[i]][i]++;
    }
  }

  for(auto it : str_vec_map) {
    stringstream ss;
    copy(it.second.begin(), it.second.end(), ostream_iterator<int>(ss, " ")); 
    res.push_back(it.first + " " + ss.str());
  }

  for(auto str : res) {
    cout << str << endl;
  }
  
  return 0;
}
