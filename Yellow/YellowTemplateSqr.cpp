#include <iostream>
#include <vector>
#include <map>
#include <utility>

template <typename T> T Sqr(T value);
template <typename T> std::vector<T> Sqr(std::vector<T>& vector);
template <typename First, typename Second> std::pair<First, Second> Sqr(std::pair<First, Second>& pair);
template <typename Key, typename Value> std::map<Key, Value> Sqr(std::map<Key, Value>& map);

template <typename T>
T Sqr(T value) {
  return value * value;
}

template <typename T>
std::vector<T> Sqr(std::vector<T>& vector) {
  for (auto& el : vector) {
    el = Sqr(el);
  }
  return vector;
}

template <typename First, typename Second>
std::pair<First, Second> Sqr(std::pair<First, Second>& pair) {
  pair.first = Sqr(pair.first);
  pair.second = Sqr(pair.second);
  return pair;
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(std::map<Key, Value>& map) {
  for (auto& [key, val] : map) {
    val = Sqr(val);
  }
  return map;
}


int main() {
  std::vector<int> a = {2, 3};
  auto b = Sqr<int>(a);
  std::cout << b[0] << " " << b[1] << std::endl;
  std::map<int, std::pair<int, int>> map_of_pairs = {
  {4, {2, 2}},
  {7, {4, 3}}
  };
  std::cout << "map of pairs:" << std::endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
  }
}