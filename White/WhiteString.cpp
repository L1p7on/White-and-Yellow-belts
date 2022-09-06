#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s1, s2, s3, result;
  std::cin >> s1;
  std::cin >> s2;
  std::cin >> s3;
  result = std::min(std::min(s1, s2), s3);
  std::cout << result << std::endl;
}