#include <iostream>
#include <vector>
using namespace std;

class Shape
{
  public:
    virtual ~Shape()  {}

    virtual Shape* clone() const = 0;
    virtual Shape* create() const = 0;
    virtual void type() const = 0;
};


class Circle : public Shape
{
  public:
    Shape* clone() const  {
      return new Circle(*this);
    }
    Shape* create() const {
      return new Circle();
    }
    void type() const {
      cout << "Circle" << endl;
    }
};

class Square : public Shape
{
  public:
    Shape* clone() const  {
      return new Square(*this);
    }
    Shape* create() const {
      return new Square();
    }
    void type() const {
      cout << "Square" << endl;
    }
};

int main()
{
  Shape *s1 = new Circle;
  Shape *s11 = s1->clone();
  Shape *s12 = s1->create();
  s1->type();
  s11->type();
  s12->type();

  Shape *s2 = new Square;
  Shape *s21 = s2->clone();
  Shape *s22 = s2->create();
  s2->type();
  s21->type();
  s22->type();

  delete s1;
  delete s11;
  delete s12;
  delete s2;
  delete s21;
  delete s22;
  
}



