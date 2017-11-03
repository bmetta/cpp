#include <iostream>
#include <map>

int main() {
  //std::multimap<char, int> m_map;
  //m_map.insert(std::make_pair<char, int>('a', 1));
  //m_map.insert(std::make_pair<char, int>('c', 2));
  //m_map.insert(std::make_pair<char, int>('b', 3));
  //m_map.insert(std::make_pair<char, int>('b', 4));
  //m_map.insert(std::make_pair<char, int>('a', 5));
  //m_map.insert(std::make_pair<char, int>('b', 6));

  std::multimap<std::string, std::string>
      m_map{
          {"a", "1"},
          {"c", "2"},
          {"b", "3"},
          {"b", "4"},
          {"a", "5"},
          {"b", "6"}};

  std::cout << "No of elements with key a: " << m_map.count("a") << std::endl;
  std::cout << "No of elements with key b: " << m_map.count("b") << std::endl;
  std::cout << "No of elements with key c: " << m_map.count("c") << std::endl;

  std::cout << "Elements in m_map: " << std::endl;
  for (auto it : m_map) {
    std::cout << it.first << " " << it.second << std::endl;
  }

  std::cout << "Elements with key 'b' in m_map: " << std::endl;
  auto range = m_map.equal_range("b");
  while (range.first != range.second) {
    std::cout << range.first->second << std::endl;
    ++range.first;
  }

  m_map.clear();
}
