#include <iostream>
#include <map>
#include <string>

template <typename Key, typename Value> Value& GetRefStrict(std::map<Key, Value>& map, Key key);

template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& map, Key key) {
  if (map.count(key) == 0) {
    throw std::runtime_error ("Why runtime_error?\n");
  }
  return map.at(key);
}

// int main() {
//   std::map<int, std::string> m = {{0, "value"}};
//   std::string& item = GetRefStrict(m, 0);
//   item = "newvalue";
//   std::cout << m[0] << std::endl; // выведет newvalue
// }