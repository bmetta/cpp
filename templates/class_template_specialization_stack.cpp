#include <iostream>
#include <vector>
using namespace std;
/* string class specialization start */
template<>
class Stack<string>
{
  private:
    int size;
    vector<string> v;

  public:
    Stack(int n);
    ~Stack();
    void push(const string&);
    string const pop();
    bool isEmpty();
};


template<typename T>
Stack<T>::Stack(int n) {
  size = n;
  cout << "Stack constructor" << endl;
}

template<typename T>
Stack<T>::~Stack() {
  cout << "Stack destructor" << endl;
}

template<typename T>
void Stack<T>::push(const T& val) {
  if(v.size() == size) {
    cout << "Stack Full" << endl;
    return;
  }
  cout << "push " << val << endl;
  v.push_back(val);
}

template<typename T>
T const Stack<T>::pop() {
  if(! isEmpty()) {
    T val = v.back();
    cout << "pop " << val << endl;
    v.pop_back();
    return val;
  }
  cout << "Stack Empty" << endl;
}

template<typename T>
bool Stack<T>::isEmpty() {
  if(v.size() == 0)
    return true;
  return false;
}
/* string class specialization end */

template<typename T>
class Stack
{
  private:
    int size;
    vector<T> v;

  public:
    Stack(int n);
    ~Stack();
    void push(const T&);
    T const pop();
    bool isEmpty();
};


template<typename T>
Stack<T>::Stack(int n) {
  size = n;
  cout << "Stack constructor" << endl;
}

template<typename T>
Stack<T>::~Stack() {
  cout << "Stack destructor" << endl;
}

template<typename T>
void Stack<T>::push(const T& val) {
  if(v.size() == size) {
    cout << "Stack Full" << endl;
    return;
  }
  cout << "push " << val << endl;
  v.push_back(val);
}

template<typename T>
T const Stack<T>::pop() {
  if(! isEmpty()) {
    T val = v.back();
    cout << "pop " << val << endl;
    v.pop_back();
    return val;
  }
  cout << "Stack Empty" << endl;
}

template<typename T>
bool Stack<T>::isEmpty() {
  if(v.size() == 0)
    return true;
  return false;
}

int main()
{
  Stack<int> intSt(5);
  intSt.push(1);  
  intSt.pop();

  Stack<string> strSt(5);
  strSt.push("Hello");  
  strSt.pop();
  return 0;
}
