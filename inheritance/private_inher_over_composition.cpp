#include <iostream>
using namespace std;

class Wilma 
{
protected:
  void fredCallsWilma() {
    std::cout << "Wilma::fredCallsWilma()\n";
    wilmaCallsFred();
  }
  virtual void wilmaCallsFred() = 0;   // A pure virtual function
};
class Fred : private Wilma 
{
public:
  void barney() {
    std::cout << "Fred::barney()\n";
    Wilma::fredCallsWilma();
  }
protected:
  virtual void wilmaCallsFred() {
    std::cout << "Fred::wilmaCallsFred()\n";
  }
};

int main()
{
  Fred f;
  f.barney();
}
