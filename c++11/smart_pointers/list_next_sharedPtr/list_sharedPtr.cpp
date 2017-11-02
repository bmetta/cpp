#include <iostream>
#include <memory>
using namespace std;

class LNode
{
private:
  int data;
  shared_ptr<LNode> next;

public:
  LNode(int data) : data(data) {}
  void add_node_last(int data) {
    if(! next) {
      next.reset(new LNode(data));
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
  shared_ptr<LNode> getNext() {
    return next;
  }
};

int main()
{
  shared_ptr<LNode> spl;
  {
    LNode root(1);
    root.add_node_last(2);
    root.add_node_last(3);
    root.add_node_last(4);

    root.display();
    cout << endl;
    
    spl = root.getNext();
  }
  spl->display();
  cout << endl;

  return 0;
}
