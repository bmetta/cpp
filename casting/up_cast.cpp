#include <iostream>
using namespace std;

class Parent {
public:
  void sleep() {
    cout << "Sleep" << endl;
  }
};

class Child: public Parent {
public:
  void gotoSchool() {
    cout << "GotoSchool" << endl;
  }
};

int main() { 
  Parent parent;
  Child  child;

  // upcast - implicit type cast allowed
  Parent *pParent = &child; 

  // downcast - explicit type case required 
  Child *pChild =  (Child *) &parent;

  pParent -> sleep();
  pChild -> gotoSchool();
    
  return 0; 
}
