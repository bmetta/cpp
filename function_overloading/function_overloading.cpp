#include<iostream>
#include<stdio.h>
  
using namespace std;
  
/********************************/
int f(int x)  /* (const int x) */ /* (int x = 10) */ { return x+10; }
int f(int* x) /* int x[] */ /* (int* const x) */     { return *x+10; }
int f(int& x)        { return x+10; }
 
int f(const int* x) { return *x+10; }
int f(const int& x) { return x+10; }

int f(volatile int* x)       { return *x+10; }
int f(volatile int& x)       { return x+10; }
int f(volatile const int* x) { return *x+10; }
/********************************/
int f(int ()) /* (int (*)()) */ { }
/********************************/
class Test
{
  protected:
    int x;

  public:
    Test(int i) : x(i) {}
    void fun()       { x = 10; cout << "fun() called" << endl; }
    void fun() const { /* x = 10; */ cout << "fun() const called" << endl; }
    void fun() volatile { cout << "fun() volatile called" << endl; }
};

int main() {

  return 0;
}
