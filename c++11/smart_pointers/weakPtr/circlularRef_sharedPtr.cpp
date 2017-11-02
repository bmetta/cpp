#include <iostream>
#include <memory>
using namespace std;

class A;
class B;

class A {
public:
  shared_ptr<B> b_refPtr;
  ~A() { cout << "A dtor" << endl; }
};

class B {
public:
  shared_ptr<A> a_refPtr;
  ~B() { cout << "B dtor" << endl; }
};

int main()
{
  shared_ptr<A> ap(new A);
  shared_ptr<B> bp(new B);

  ap->b_refPtr = bp;
  bp->a_refPtr = ap;

  return 0;
}
