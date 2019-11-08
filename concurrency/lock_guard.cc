// Two threads increments a shared variable
#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex m;

void worker() {
  std::lock_guard<std::mutex> lock(m);
  //m.lock();
  count++;
  std::cout << "thread id: " << std::this_thread::get_id
            << " count: " << count << std::endl;
  //m.unlock();
  // mutex m is automatically released when lock goes out of scope
}

int main() {
  std::thread t1(worker);
  std::thread t2(worker);

  t1.join();
  t2.join();
}
