#include <iostream>
#include <memory>
#include <iomanip>
using namespace std;

class Investment {
private:
  int investType;
public:
  Investment(int type): investType(type) { }
  virtual ~Investment() {}
  // Factory method
  static unique_ptr<Investment> makeInvestment(int investType);
  virtual void order() = 0;
  int getInvestType() { return investType; }
};

class Stock : public Investment {
public:
  Stock(int type) : Investment(type) {}
  void order() {
    cout << "Stock purchase order" << endl;
  }
};

class Bond : public Investment {
public:
  Bond(int type) : Investment(type) {}
  void order() {
    cout << "Bond purchase order" << endl;
  }
};

class RealEstate : public Investment {
public:
  RealEstate(int type) : Investment(type) {}
  void order() {
    cout << "RealEstate purchase order" << endl;
  }
};

void makeLogEntry(Investment* pInv) 
{
  cout << "pInv deleted for type " << pInv->getInvestType() << endl;
}

auto delInvmt = [ ](Investment* pInv) {
                  makeLogEntry(pInv);
                  delete pInv;
                };

unique_ptr<Investment> Investment::makeInvestment(int investType)
{
  unique_ptr<Investment, Investment> pInv(nullptr, delInvmt);

  // Stock
  if(investType == 1) {
    pInv.reset(new Stock(investType));
  } else if(investType == 2) {
    pInv.reset(new Bond(investType));
  } else if(investType == 3) {
    pInv.reset(new RealEstate(investType));
  }
  return pInv;
}
//    User ----->         Investment (FactoryMethod: makeInvestment)
//                ^           ^           ^
//                |           |           |
//              Stock       Bond      RealEstate

int main()
{
  auto pInvStock = Investment::makeInvestment(1);
  pInvStock->order();

  auto pInvBond = Investment::makeInvestment(2);
  pInvBond->order();
  
  auto pInvRe = Investment::makeInvestment(3);
  pInvRe->order();

  return 0;
}
