#include <iostream>
#include <algorithm>
int main() {
  std::string s;
  std::cin >> s;
  auto first_time = std::find(s.begin(), s.end(), 'f');
  if (first_time == s.end()) {
    std::cout << -2 << std::endl;
  } else {
    auto second_time = std::find(first_time + 1, s.end(), 'f');
    if (second_time == s.end()) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << second_time - s.begin() << std::endl;
    }
  }
}