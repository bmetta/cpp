#include <iostream>
using namespace std;

class ArrayWrapper {
 public:
  ArrayWrapper(int n) : _size(n), _pArr(new int[n]) { }
  ~ArrayWrapper() { 
    cout << "dtor called" << endl;
    delete[] _pArr; 
  }

  // copy ctor
  ArrayWrapper(const ArrayWrapper& obj) 
    : _size(obj._size), _pArr(new int[_size]) {
    cout << "copy ctor called" << endl;
    for(int i = 0; i < _size; i++) {
      _pArr[i] = obj._pArr[i];
    }
  }
  
  // move ctor
  ArrayWrapper(ArrayWrapper&& obj)
    : _size(obj._size), _pArr(obj._pArr) {
    cout << "move ctor called" << endl;

    obj._pArr = NULL;
    obj._size = 0;
  }

  void setArray(int* arr, int n) {
    for(int i = 0; i < n; i++) {
      _pArr[i] = arr[i];
    }
  }

  void printArray() {
    for(int i = 0; i < _size; i++) {
      cout << _pArr[i] << " ";
    }
    cout << endl;
  }

 private:
  int* _pArr;
  int _size;
};

int main() {
  int a[] = {10, 20, 30, 40, 50};
  ArrayWrapper arr1(5);
  arr1.setArray(a, 5);
  arr1.printArray();

  ArrayWrapper arr2(move(arr1));
  arr2.printArray();
  
  return 0;
}
