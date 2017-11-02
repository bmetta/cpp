#include <iostream>
#include <vector>
using namespace std;

class Vehicle  {
  public:
    virtual void vehicleType() = 0;
};

class Car : public Vehicle  {
  public:
    void vehicleType()  {
      cout << "Car" << endl;
    }
};

class Truck : public Vehicle  {
  public:
    void vehicleType()  {
      cout << "Truck" << endl;
    }
};

int main()
{
  vector<Vehicle*> list;
  vector<Vehicle*>::iterator it;

  list.push_back(new Car);
  list.push_back(new Truck);

  for(it = list.begin(); it != list.end(); ++it)  {
    Vehicle &v = **it;
    v.vehicleType();
  }
}
