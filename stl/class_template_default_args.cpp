#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <class T, class CONT = vector<T> >
class Stack
{
  private:
    int size;
    CONT elem;

  public:
    Stack(int = 5);
    ~Stack();
    void push(const T);
    void pop();
    const T top();
};

template<class T, class CONT>
Stack<T, CONT>::Stack(int n) {
  cout << "constructor" << endl;
  size = n;
}

template<class T, class CONT>
Stack<T, CONT>::~Stack() {
  cout << "destructor" << endl;
}

template<class T, class CONT>
void Stack<T, CONT>::push(const T data) {
  if(elem.size() == size) {
    cout << "Stack is full" << endl;
    return;
  }
  elem.push_back(data);
}

template<class T, class CONT>
void Stack<T, CONT>::pop() {
  if(elem.size() == 0) {
    cout << "Stack is empty" << endl;
    return;
  }
  elem.pop_back();
}

template<class T, class CONT>
const T Stack<T, CONT>::top() {
  if(elem.size() == 0) {
    throw out_of_range("Stack empty");
  }
  return elem.back();
}

int main()
{
  try {
    Stack<int, deque<int> > st;
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
