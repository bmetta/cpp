#include <iostream>
#include <memory>
using namespace std;

class A;
class B;

class A {
public:
  weak_ptr<B> b_refPtr;
  ~A() { cout << "A dtor" << endl; }
  void do_something() {
    shared_ptr<B> sp = b_refPtr.lock();
    if(sp) cout << "A: weakPtr is alive" << endl;
    else cout << "A: weakPtr is expired" << endl;
  }
};

class B {
public:
  weak_ptr<A> a_refPtr;
  ~B() { cout << "B dtor" << endl; }
  void do_something() {
    shared_ptr<A> sp = a_refPtr.lock();
    if(sp) cout << "B: weakPtr is alive" << endl;
    else cout << "B: weakPtr is expired" << endl;
  }
};

int main()
{
  shared_ptr<A> ap(new A);
  shared_ptr<B> bp(new B);

  ap->b_refPtr = bp;
  bp->a_refPtr = ap;

  ap->do_something();
  bp->do_something();

  return 0;
}
