#include <iostream>
using namespace std;

class Engine {
public:
  Engine(int numCylinders) {}
  // Starts this Engine
  void start()  {cout << "Start" << endl; }
};

class Car : private Engine {    // Car has-a Engine
public:
  Car() : Engine(8) { }         // Initializes this Car with 8 cylinders
  using Engine::start;          // Start this Car by starting its Engine
};

int main()
{
  Car c;
  c.start();

  Engine *e = new Car();
}
