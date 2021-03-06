#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Widget : public enable_shared_from_this<Widget> {
private:
  static vector<shared_ptr<Widget>> processedWidget;
  Widget() {}

public:
  void process();
  static shared_ptr<Widget> create();
};


shared_ptr<Widget> Widget::create()
{
  shared_ptr<Widget> w1(new Widget);
  return w1;
}

void Widget::process()
{
//  processedWidget.push_back(this);
  processedWidget.push_back(shared_from_this());
}

vector<shared_ptr<Widget>> Widget::processedWidget;

int main()
{
//  shared_ptr<Widget> w1(new Widget);

  /* Internally shared_from_this looks up the control block for the current object, 
   * and it creates a new shared_ptr that refers to that control block */
//  Widget *w1 = new Widget;

  auto w1 = Widget::create();
  w1->process();

  return 0;
}
