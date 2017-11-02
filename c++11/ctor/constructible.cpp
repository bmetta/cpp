#include <iostream>
#include <type_traits>
using namespace std;

struct As {
  As()=default;
  As(As&&)=delete;
  As(const As&)=default;
  As& operator=(As&&)=delete;
  As& operator=(const As&)=delete;
  ~As()=default;
};

int main() {
  cout << is_move_constructible<As>::value << endl;
  cout << is_copy_constructible<As>::value << endl;
  
  As a;
  //As b = move(a);   // not ok; move ctor marked as delete
  As b = a;
  As c;

  //c = move(a);      // not ok; move assignment op marked as delete
  //c = a;            // not ok; assignment op marked as delete
  return 0;
}
