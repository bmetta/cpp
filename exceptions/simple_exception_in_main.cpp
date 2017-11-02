#include <iostream>
#include <cstdlib>
using namespace std;
/*
int main(int argc, char *argv[])
{
  cout << argc << " " << argv[0] << " " << argv[1] << endl;
  int flag = atoi (argv[1]);
  cout << flag << endl;
  cout << "Before try" << endl;
  try {
    cout << "Inside try" << endl;

    cout << "Throw exception" << endl;
    if(flag == 1)
     throw 10;
    else if (flag == 2)
     throw 10.5;
    else
     throw 'A';

    cout << "After exception thrown" << endl;
  }
  catch (int x){
    cout << "int exception caught value: " << x << endl;
  }
  catch (double d){
    cout << "double exception caught value: " << d << endl;
  }
  catch (...){ // catch all
    cout << "other types exception caught value: " << endl;
  }
  cout << "After catch" << endl;

  return 0;
}
*/

int main()
{
  try {
    try {
      throw 20;
    }
    catch(int n) {
      cout << "handle partially [value]: " << n << endl;
      throw;
    }
  } 
  catch (int n) {
    cout << "handle remaining [value]: " << n << endl;
  }
}
