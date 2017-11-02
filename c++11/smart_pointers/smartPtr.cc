#include <iostream>
#include <cstdlib>

class SmartPtr {
private:
  SmartPtr()  { std::cout << "ctor\n"; }
  ~SmartPtr() { std::cout << "dtor\n"; }

public:
  void* operator new(std::size_t count) {
    std::cout << "operator new called\n";
    return std::malloc(count);
  }
  void operator delete(void* ptr) {
    std::cout << "operator delete called\n";
    free(ptr);
  }

  void display() {
    std::cout << "display\n";
  }
};

int main() {
  SmartPtr *sp = new SmartPtr;

  delete sp;

  return 0;
}
