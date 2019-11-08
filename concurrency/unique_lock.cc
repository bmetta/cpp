// Transfer amount between two accounts
#include <iostream>
#include <thread>
#include <mutex>

struct Account {
  Account(int amount) : balance{amount} {}
  int balance;
  std::mutex m;
};

void transfer(Account &from, Account &to, int amount) {
  // dont actually takes the locks yet
  std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
  std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

  // lock both unique_locks without deadlock
  std::lock(lock1, lock2);
  from.balance -= amount;
  to.balance += amount;
}

int main() {
  Account a1(100);
  Account a2(200);

  std::thread t1(transfer, std::ref(a1), std::ref(a2), 30);
  std::thread t2(transfer, std::ref(a2), std::ref(a1), 10);

  t1.join();
  t2.join();
  std::cout << "A1 balance: " << a1.balance << std::endl;
  std::cout << "A2 balance: " << a2.balance << std::endl;
}
