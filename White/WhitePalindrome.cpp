#include <iostream>
#include <string>

bool IsPalindrom(std::string s) {
  if (s.empty()) {
    return true;
  }
  size_t j = s.size() - 1;
  size_t i = 0;
  for (; i <= s.size()/2 && j >= s.size()/2; ++i, --j) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

// int main() {
//   std::cout << IsPalindrom("") << std::endl;
//   std::cout << IsPalindrom("X") << std::endl;
//   std::cout << IsPalindrom("mad am") << std::endl;
//   std::cout << IsPalindrom("gentleman") << std::endl;
// }