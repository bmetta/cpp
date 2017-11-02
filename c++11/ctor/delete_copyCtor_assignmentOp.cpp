#include <iostream>
using namespace std;

class Handle {
private:
  string name;
  int *ptr;
  Handle(const Handle &) = delete;
  Handle& operator=(const Handle &) = delete;

public:
  Handle(string n) : name(n), ptr(0)  {}
  ~Handle() {delete ptr;}
};

int main() {
  Handle h1("Hi");
  Handle h2 = h1;
}
