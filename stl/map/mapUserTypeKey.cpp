#include <iostream>
#include <map>
using namespace std;

class UserType
{
  private:
    int x;
    int y;
  public:
    UserType(int i, int j): x(i), y(j) {}
    int getX() {return x;}
    int getY() {return y;}
    bool operator<(const UserType &temp) const {
      return x < temp.x;
    }
};

int main()
{
  map<UserType, int> userMap;
  UserType obj1(10, 20);

  userMap[obj1] = 1111;

  cout << userMap[obj1];
}
