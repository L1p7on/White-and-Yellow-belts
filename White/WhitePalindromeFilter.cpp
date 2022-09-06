#include <iostream>
#include <vector>
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

std::vector<std::string>  PalindromFilter(std::vector<std::string>& vector,
                                          int minLength) {
  std::vector<std::string> result;
  for (size_t i = 0; i < vector.size(); ++i) {
    if (vector[i].size() < minLength) {
      continue;
    } 
    if (IsPalindrom(vector[i])) {
      result.push_back(vector[i]);
    }
  }
  return result;
}

// int main() {
//   std::vector<std::string> s = {"abc", "aba"};
//   auto t = PalindromFilter(s, 2);
//   std::cout << t[0] << std::endl;
// }