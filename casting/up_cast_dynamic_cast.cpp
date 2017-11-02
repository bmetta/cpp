#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
  virtual void sleep() {
  }
};

class Child: public Parent {
private:
  std::string classes[10];
public:
  void gotoSchool(){}
};

int main( ) 
{ 
/*
  Parent *pParent = new Parent;
  Parent *pChild = new Child;
    
  Child *p1  = dynamic_cast<Child*>(pParent);  // #1
  if(!p1)
    cout <<"p1 not allowed" << endl;
  Parent *p2 = dynamic_cast<Parent*>(pChild);   // #2
  if(!p2)
    cout <<"p2 not allowed" << endl;
*/

  Parent *p1 = dynamic_cast<Parent*> (new Parent);
  if(p1)
    cout << "Parent -> Parent Yes" << endl;
  else
    cout << "Parent -> Parent No" << endl;

  Parent *p2 = dynamic_cast<Parent*> (new Child);
  if(p2)
    cout << "Parent -> Child Yes" << endl;
  else
    cout << "Parent -> Child No" << endl;

  Child *c1 = dynamic_cast<Child*> (new Child);
  if(c1)
    cout << "Child -> Child Yes" << endl;
  else
    cout << "Child -> Child No" << endl;

  Child *c2 = dynamic_cast<Child*> (new Parent);
  if(c2)
    cout << "Child -> Parent Yes" << endl;
  else
    cout << "Child -> Parent No" << endl;

  Parent *p = new Child; // upcasting
  Child *c = dynamic_cast<Child*>(p); // downcasting

  if(c)
    cout << "downcasting success" << endl;

  return 0; 
}
