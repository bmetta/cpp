#include <iostream>

class A {
  int i;

public: 
  A(int x) : i (x) {}
};

int main() {
  const A *a = new A(1);
  
  return 0;
}
