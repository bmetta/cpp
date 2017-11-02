#include <iostream>
#include <string>

class EmailProcessor {
public:
  void receiveMessage(const std::string& message) {
    if(_handler_func) {
      std::cout << "calling handler func" << std::endl;
      _handler_func(message);
    }
  }
  void setHandlerFunc(std::function<void (const std::string &)> handler_func) {
    _handler_func = handler_func;
  }

private:
  std::function<void (const std::string &)> _handler_func;
};

class MessageSizeStore {
public:
  MessageSizeStore() : _maxSize(0) {}
  
  void checkMessage(const std::string &message) {
    std::cout << "checking the message size" << std::endl;
    if(message.size() > _maxSize)
      _maxSize = message.size();
  }

private:
  int _maxSize;
};

int main() {
  MessageSizeStore messageSizeStore;
  EmailProcessor emailProcessor;

  emailProcessor.setHandlerFunc(
    [&](const std::string &message) { messageSizeStore.checkMessage(message); } 
  );
  emailProcessor.receiveMessage("Hello");
  return 0;
}
