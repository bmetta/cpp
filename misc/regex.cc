// regex_search example
#include <iostream>
#include <string>
#include <regex>
#include <map>

int main ()
{
  const char *str = "OK\n";
  std::string response(reinterpret_cast<const char*>(str), 6);
  std::string res(response.cbegin(), response.cend() - 1);
  std::cout << "response " << res;
  const std::multimap<std::string, std::regex>
      responses{
        {"ADD", std::regex("(OK)(.*)")},
        {"ADD", std::regex("(FAIL)(.*)")},
        {"DEL", std::regex("(OK)(.*)")},
        {"DEL", std::regex("(FAIL)(.*)")}};

  auto range = responses.equal_range("ADD");
  while (range.first != range.second) {
    if (std::regex_match(response.cbegin(), response.cend() - 1, range.first->second)) {
      std::cout << "matched\n";
      return true;
    }
    ++range.first;
  }
  std::cout << "not matched\n";
  return false;
}
