#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
 public:
  virtual ~Singleton() = default;
  // copy ctor is not allowed
  Singleton(const Singleton&) = delete;
  // move ctor is not allowed
  Singleton(Singleton&&) = delete;
  // assignment operator is not allowed
  Singleton& operator=(const Singleton&) = delete;
  // move assignment operator is not allowed
  Singleton& operator=(Singleton&&) = delete;

  int count;
  static Singleton& GetInstance() {
    static std::unique_ptr<Singleton> instance(new Singleton());
    instance->count = 100;
    return *instance.get();
  }

 private:
  Singleton() {
    std::cout << "ctor" << std::endl;
  }
};

int main() {
  Singleton &inst1 = Singleton::GetInstance();
  inst1.count = 10;
  Singleton &inst2 = Singleton::GetInstance();
  inst2.count = 20;

  std::cout << inst1.count << std::endl;
  std::cout << inst2.count << std::endl;

  Singleton &&inst3(std::move(inst2));
  inst3.count = 30;
  std::cout << inst1.count << std::endl;
  std::cout << inst2.count << std::endl;
  std::cout << inst3.count << std::endl;
}
