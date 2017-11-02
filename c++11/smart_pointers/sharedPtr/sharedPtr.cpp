#include <memory>
#include <iostream>
using namespace std;

class Thing
{
private:
  int objId;
  static int count;

public:
  Thing() { 
    objId = count++; 
    cout << "ctor objId: " << objId << endl; 
  }
  ~Thing() { cout << "dtor objId: " << objId << endl; }
  void defrangulate() { cout << "defrangulate" << endl; }
};

int Thing::count = 0;

shared_ptr<Thing> find_some_thing()
{
  shared_ptr<Thing> temp(new Thing);
  cout << "find_some_thing" << endl;
  return temp;
}
shared_ptr<Thing> do_something_with(shared_ptr<Thing> p)
{
  cout << "do_something_with" << endl;
  return p;
}

int main()
{
/*
  shared_ptr<Thing> p1(new Thing);
  shared_ptr<Thing> p2 = p1;

  shared_ptr<Thing> p3(new Thing);
  
  p1 = find_some_thing(); // p1 no longer point to first Thing
  do_something_with(p2);

  p3->defrangulate();
*/

  shared_ptr<Thing> p1(new Thing);
  shared_ptr<Thing> p2 = p1;

  cout << p1 << " " << p2 << endl;
  cout << p1.get() << " " << p2.get() << endl;
  cout << p1.use_count() << " " << p2.use_count() << endl;
  p2.reset(); // decrement count, delete if last
//  p2 = nullptr; // convert nullptr to an empty shared_ptr, and decrement count
  cout << p1 << " " << p2 << endl;
  cout << p1.use_count() << " " << p2.use_count() << endl;

  shared_ptr<Thing> p3(new Thing);

  return 0;
}
