#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;

bool notify_worker = false; // worker thread waits on it
bool notify_main = false; // main thread waits on it

std::string data;

void worker() {
  std::unique_lock<std::mutex> lk(m);
  std::cout << "[worker thread]: wait until main sends data" << std::endl;
  cv.wait(lk, [] {return notify_worker == true;});
  std::cout << "[worker thread]: worker ready" << std::endl;

  data += "worker thread processed data";
  std::cout << "[worker thread]: processed data and notifying main thread" << std::endl;
  notify_main = true;
  cv.notify_one();
}

int main() {
  std::cout << "[main thread]: creating a worker thread" << std::endl;
  std::thread t(worker);

  data = "data to worker; ";
  // send data and unblock worker
  {
    std::lock_guard<std::mutex> lk(m);
    notify_worker = true;
    cv.notify_one();
    std::cout << "[main thread]: notifying worker" << std::endl;
  }

  // wait for the worker
  {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] {return notify_main == true;});
  }
  std::cout << "[main thread]: date: " << data << std::endl;
  t.join();
}
