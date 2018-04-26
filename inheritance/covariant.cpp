#include <iostream>
using namespace std;

class Dog {};
class Puppy : public Dog {};

template<typename T>
class Animal {
  T animal;
};

class AnimalCarer {
  Animal<Dog> *dog;

 public:
  AnimalCarer(Animal<Dog> *d) { dog = d; }
};

int main() {
  Animal<Dog> *dogAnimal = new Animal<Dog>;
  AnimalCarer *dogCarer = new AnimalCarer(dogAnimal);

  Animal<Puppy> *puppyAnimal = new Animal<Puppy>;
  AnimalCarer *puppyCarer = new AnimalCarer(puppyAnimal);
}
