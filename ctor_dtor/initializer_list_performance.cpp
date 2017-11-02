#include <iostream>
using namespace std;

class Test
{
public:
  Test() { cout << "Test constructor" << endl;  }
  ~Test() { cout << "~Test destructor" << endl;  }
  Test(const Test& obj)  { cout << "Test copy constructor" << endl;  }
  void operator=(const Test& obj) { cout << "Test assignment operator" << endl;  }
};

class User
{
  Test t;
public:
  User(Test& a) /* : t(a) */ {
    cout << "User constructor" << endl;
    t = a;
  }
  ~User() { cout << "~User destructor" << endl;  }
};

int main()
{
  Test t;
  cout << "***********" << endl;
  User obj(t);
  cout << "***********" << endl;
  
  return 0;
}
