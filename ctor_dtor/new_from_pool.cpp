/*
class Pool {
public:
  void* alloc(size_t nbytes);
  void dealloc(void* p);
private:
  // ...data members used in your pool object...
};
void* Pool::alloc(size_t nbytes)
{
  // ...your algorithm goes here...
}
void Pool::dealloc(void* p)
{
  // ...your algorithm goes here...
}

Pool pool;
void* raw = pool.alloc(sizeof(Foo));
Foo* p = new(raw) Foo();
// or

Foo* p = new(pool.alloc(sizeof(Foo))) Foo();
// or

new(pool) Foo() // calls below
inline void* operator new(size_t nbytes, Pool& pool)
{
  return pool.alloc(nbytes);
}

void sample(Pool& pool)
{
  Foo* p = new(pool) Foo();
  // ...
  p->~Foo();        // explicitly call dtor
  pool.dealloc(p);  // explicitly release the memory
}

void operator delete(void* p, Pool& pool)
{
  pool.dealloc(p);
}
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
public:
  int isFree;

  Point()  { cout << "ctor " << this << endl; }
  ~Point() { cout << "dtor " << this << endl; }
};

class Pool {
public:
  Pool()  { }
  ~Pool() { }

  void* alloc(size_t nbytes)  {
    for(int i = 0; i < 10; i++) {
      if(p[i].isFree) {
        cout << "Free index: " << i << endl;
        p[i].isFree = false;
        return &p[i];
      }
    }
    return NULL;
  }
  void dealloc(Point* p) { p->isFree = true; }
  void init() {
    for(int i = 0; i < 10; i++) {
      p[i].isFree = true;
    }
  }

private:
  Point p[10];
};

Pool pool;

void* operator new(size_t size)  {
  void *p = malloc(size);
  cout << "new size: " << size << " " << p << endl;
  return p;
}

void* operator new(size_t size, Pool &pool)  {
  Point *p;
  void *raw = pool.alloc(size);
  cout << "new from pool: " << size << " " << raw << endl;
  
  //try {
  //  p = new(raw) Point();
  //} catch (...) {
  //  operator delete(raw);
  //  throw;
  //}
  return raw;
}

void operator delete(void *p) {
  cout << "delete " << p << " " << endl;
//  free(p);
  pool.dealloc((Point*)p);
}

int main() {
  cout << "=====  main begin  ===\n";
  pool.init();

  Point *t1 = new(pool) Point();
  cout << "t1: " << t1 << endl;

  //Point *t2 = new(pool) Point();
  //cout << "t2: " << t2 << endl;

  //Point *t3 = new(pool) Point();
  //cout << "t3: " << t3 << endl;
  
  delete t1;
  //delete t2;
  //delete t3;
  cout << "=====  main exit  ===\n\n";
}
