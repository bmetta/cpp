#include <iostream>
using namespace std;

/*
class Array {
public:
  Array() {
    for(int i = 0; i < 10; i++)
      data[i] = 0;
  }
  int& elem(unsigned i) { 
    return data[i]; 
  }
  void dispaly()  {
    for(int i = 0; i < 10; i++)
      cout << data[i] << " ";
    cout << endl;
  }
private:
  int data[10];
};
int main()
{
  Array a;
  a.elem(6) = 42;
  a.elem(0) = 9;
  a.elem(0) += a.elem(6);
  a.dispaly();
}
*/

class Array {
public:
  Array() {
    for(int i = 0; i < 10; i++)
      data[i] = 0;
  }
  int& operator[](int i)  {
    return data[i];
  }
  void dispaly()  {
    for(int i = 0; i < 10; i++)
      cout << data[i] << " ";
    cout << endl;
  }
private:
  int data[10];
};
int main()
{
  Array a;
  a[6] = 42;
  a[0] = 9;
  a[0] += a[6];
  a.dispaly();
}
