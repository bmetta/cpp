
class Bar {
public:
  Bar() {}
};

class Foo { 
public:
  Foo(const Bar& b){}  // or perhaps Foo(Bar b)
  void blah() {}
};

void yourCode() {
//  Foo x1(Bar());      // You think this creates a Foo object called x...
  
  Foo x2((Bar()));  // It creates X object
  Foo x3 = Bar();   // It creates X object

  x3.blah();        // ...But it doesn't, so this line gives you a bizarre error message
}

int main() {
  yourCode();
}
