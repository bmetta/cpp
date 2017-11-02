#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void display(vector<vector<int> > &vec )
{
  for(int i = 0; i < vec.size(); i++) {
    for(int j = 0; j < vec[i].size(); j++) {
      cout << setw(2) << vec[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  vector<vector <int> > vec;
  for(int i = 0; i < 5; ++i) {
    vec.push_back(vector<int>());
    for(int j = 0; j < 5; j++) {
      vec[i].push_back(i*j);
    }
  }
  display(vec);
  int rows = 5, cols = 5;
  vector<vector <int> > vec1(rows, vector<int>(cols, 0));
  display(vec1);
}
