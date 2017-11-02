#include <iostream>
#include <vector>
using namespace std;

template <class T, int MAX_SIZE = 5>
class Stack
{
  private:
    int size;
    vector<T> elem;

  public:
    Stack();
    ~Stack();
    void push(const T);
    void pop();
    const T top();
};

template  <class T, int MAX_SIZE>
Stack<T, MAX_SIZE>::Stack() {
  cout << "constructor" << endl;
  size = MAX_SIZE;
}

template  <class T, int MAX_SIZE>
Stack<T, MAX_SIZE>::~Stack() {
  cout << "destructor" << endl;
}

template<class T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::push(const T data) {
  if(elem.size() == size) {
    cout << "Stack is full" << endl;
    return;
  }
  elem.push_back(data);
}

template<class T, int MAX_SIZE>
void Stack<T, MAX_SIZE>::pop() {
  if(elem.size() == 0) {
    cout << "Stack is empty" << endl;
    return;
  }
  elem.pop_back();
}

template<class T, int MAX_SIZE>
const T Stack<T, MAX_SIZE>::top() {
  if(elem.size() == 0) {
    throw out_of_range("Stack empty");
  }
  return elem.back();
}

int main()
{
  try {
    Stack<int, 10> st;
    st.push(10);
    cout << "top: " << st.top() << endl;
    st.pop();
    cout << "top: " << st.top() << endl;
  } catch(exception const& ex) {
    cout << "Exception: " << ex.what() << endl;
    return 1;
  }
  return 0;
}
