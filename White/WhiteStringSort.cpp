#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

std::string Transform(const std::string& s) {
  std::string result(s);
  //result = s;
  std::transform(s.begin(), s.end(), result.begin(), [](char c) {
    return std::tolower(c);
  });
  return result;
}
int main() {
  size_t n = 0;
  std::cin >> n;
  std::vector<std::string> A(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  std::sort(A.begin(), A.end(), [](std::string s, std::string d) {
    return Transform(s) < Transform(d);
  });
  for (const auto& el : A) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}