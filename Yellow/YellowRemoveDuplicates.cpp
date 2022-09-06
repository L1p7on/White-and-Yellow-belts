#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
void RemoveDuplicates(std::vector<T>& elements) {
  std::sort(elements.begin(), elements.end());
  auto it = std::unique(elements.begin(), elements.end());
  elements.resize(it - elements.begin());
}

int main() {
  std::vector<std::string> A = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates<std::string>(A);
  for (const auto& el : A) {
    std::cout << el << ' ';
  }
  std::cout << std::endl;
}