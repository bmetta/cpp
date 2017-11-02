// A class can have a static member of self type
#include<iostream>
 
using namespace std;
 
class Test {
public:
  /* Static varibales donot contribute to the size of objects */
  static Test self;  // works fine
 
  /* other stuff in class*/
  int x;
 
};
 
int main()
{
  Test t;
    
  cout << "size: " << sizeof(t) << endl;
  cout << "size: " << sizeof(t.self) << endl;

  return 0;
}
