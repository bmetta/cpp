#include <iostream>
#include <vector>
#include <string>

class Address_book {
public:
  Address_book(const std::initializer_list<std::string> &list) {
    for(auto it = list.begin(), end = list.end(); it != end; it++) {
      _addresses.push_back(*it);
    }
  }
  ~Address_book() {
    while(_addresses.size()) {
      _addresses.pop_back();
    }
  }

  void show() const {
    for(auto it = _addresses.begin(), end = _addresses.end(); it != end; it++) {
      std::cout << *it << std::endl;
    }
  }

  // return list of matching addresses
//  template<typename FUNC>
//  std::vector<std::string> findMatchingAddresses(FUNC func) {
  std::vector<std::string> findMatchingAddresses(
              std::function<bool (const std::string&)> func) {
    std::vector<std::string> results;

    for(auto it = _addresses.begin(), end = _addresses.end(); it != end; ++it) {
      if(func(*it)) {
        results.push_back(*it);
      }
    }
    return results;
  }

private:
  std::vector<std::string> _addresses;
};

int main() {
  Address_book book{"abc@org.com", "xyz@org.com", "lmn@gmail.com"};
  //book.show();

  std::string name = "org.";
  std::vector<std::string> results = book.findMatchingAddresses(
          [&](const std::string &addr) { return addr.find(name) != std::string::npos; } );
  // [&] variable capture, here its variable |name|
  /*
  for (auto addr : results) {
    std::cout << addr << std::endl;
  }
  */
  for_each(results.begin(), results.end(), 
          [](const std::string &addr) { std::cout << addr << std::endl; });

  return 0;
}
