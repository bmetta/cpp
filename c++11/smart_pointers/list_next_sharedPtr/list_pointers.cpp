#include <iostream>
using namespace std;

class LNode
{
private:
  int data;
  LNode* next;

public:
  LNode(int data, LNode* p = NULL) : data(data), next(p) {}
  ~LNode() {
    delete next;
    next = NULL;
    cout << "destructed data = " << data << endl;
  }
  void add_node_last(int data) {
    if(! next) {
      next = new LNode(data);
      return;
    }
    next->add_node_last(data);
  }
  void display()  {
    cout << data << " ";
    if(next) {
      next->display();
    }
  }
};

int main()
{
  LNode root(1);

  root.add_node_last(2);
  root.add_node_last(3);
  root.add_node_last(4);

  root.display();
  cout << endl;

  return 0;
}
