#include<iostream>
using namespace std;
 
class B { virtual void fun() {} };
class D: public B { };
 
int main()
{
  B *bb = new B;
  B *bd = new D;
  D *d;

  d = dynamic_cast<D*>(bd);
  if(d != NULL) cout<<"works\n";
  else cout<<"cannot cast B* to D*\n";

  d = dynamic_cast<D*>(bb);
  if(d != NULL) cout<<"works\n";
  else cout<<"cannot cast D* to B*\n";

  return 0;
}
