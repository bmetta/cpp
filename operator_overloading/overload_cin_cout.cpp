#include <iostream>
using namespace std;
 
class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)
    {  real = r;   imag = i; }
    void set_real()  {
      cout << "Enter Real Part ";
      cin >> real;
    }
    void set_img()  {
      cout << "Enter Imagenory Part ";
      cin >> imag;
    }
//    friend ostream & operator << (ostream &out, const Complex &c);
//    friend istream & operator >> (istream &in,  Complex &c);
};
 
ostream & operator << (ostream &out, const Complex &c)
{
//    out << c.real;
//    out << "+i" << c.imag << endl;
    return out;
}
 
istream & operator >> (istream &in,  Complex &c)
{
  c.set_real();
  c.set_img();
  return in;
}
 
int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}
