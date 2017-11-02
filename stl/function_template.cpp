#include <iostream>
using namespace std;

// function declaration and definition
template <class any_data_type>
any_data_type MyMax(any_data_type Var1, any_data_type Var2)
{
  // if var1 is bigger than Var2, then Var1 is the maximum
  return Var1 > Var2 ? Var1:Var2;
}

int main()
{
  cout<<"MyMax(10,20) = "<<MyMax(10,20)<<endl;
  cout<<"MyMax('Z','p') = "<<MyMax('Z','p')<<endl;
  cout<<"MyMax(1.234,2.345) = "<<MyMax(1.234,2.345)<<endl;
}
