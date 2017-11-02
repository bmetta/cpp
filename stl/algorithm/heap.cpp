#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<int> &v)
{
  vector<int>::iterator it;
  for(it = v.begin(); it != v.end(); ++it)
    cout << setw(3) << *it;
  cout << endl;

}

bool compare(int &a, int &b)
{
  return (a < b); //max heap
//  return (a > b); // min heap
}

int main()
{
  int arr[] = {20, 10, 30, 5, 15, 10};
  vector<int> v(arr, arr+6);
  display(v);

  /* heapify */
  make_heap(v.begin(), v.end(), compare);
  display(v);

  /* top element moved to end of the vector and reduces the size from heap 
   * pop_back from vector does the vector size reduction by one
   */
  pop_heap(v.begin(), v.end(), compare); v.pop_back();
  display(v);

  v.push_back(99); push_heap(v.begin(), v.end(), compare);
  display(v);

  sort_heap(v.begin(), v.end(), compare);
  display(v);

  return 0;
}
