#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Investment {
private:
  int type;
public:
  Investment(int type) : type(type) {}
  virtual ~Investment() {}
  int getType() { return type; }
  virtual void investmentType() = 0;

  static auto makeInvestment(int invtType);
};

class Stock : public Investment {
public:
  Stock(int type) : Investment(type)  {}
  void investmentType() { 
    cout << "Stock type " << getType() << endl;  
  }
};

class Bond : public Investment {
public:
  Bond(int type) : Investment(type)  {}
  void investmentType() { 
    cout << "Bond type " << getType() << endl;  
  }
};

class RealEstate : public Investment {
public:
  RealEstate(int type) : Investment(type)  {}
  void investmentType() { 
    cout << "RealEstate type " << getType() << endl;  
  }
};

auto delInvmt = [](Investment* pInv) { delete pInv; };

auto Investment::makeInvestment(int invtType)
{
  unique_ptr<Investment, decltype(delInvmt)> pInv(nullptr, delInvmt);

  if(invtType == 1) {
    pInv.reset(new Stock(invtType));
  } else if(invtType == 2) {
    pInv.reset(new Bond(invtType));
  } else if(invtType == 3) {
    pInv.reset(new RealEstate(invtType));
  }

  return move(pInv);
}

int main()
{
  vector<unique_ptr<Investment, decltype(delInvmt)>> investVect;

  for(const auto& i: {1, 2, 3}) {
    auto pInv = Investment::makeInvestment(i);
    investVect.push_back(move(pInv));
  }

  for(const auto& pInv: investVect) {
    pInv->investmentType();
  }

  return 0;
}
