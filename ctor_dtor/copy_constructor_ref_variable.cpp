#include<iostream>
using namespace std;
 
class Test {
private:
  int x;
  int &ref;

public:
  //Test(const Test &t) { /* Copy data members from t*/}
  Test(int x = 0) : x(x), ref(x)  { /* Initialize data members */ }
};
 
int main() {
  Test t1;
  Test t2 = t1;

  return 0;
}
