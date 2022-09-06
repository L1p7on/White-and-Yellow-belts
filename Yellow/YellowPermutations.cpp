#include <vector>
#include <algorithm>
#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (size_t i = 0; i < numbers.size(); ++i) {
    numbers[i] = i+1;
  }
  std::sort(numbers.rbegin(), numbers.rend());
  for (const auto& el : numbers) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  while (std::prev_permutation(numbers.begin(), numbers.end())) {
    for (const auto& el : numbers) {
      std::cout << el << " ";
    }
    std::cout << std::endl;
  }
}