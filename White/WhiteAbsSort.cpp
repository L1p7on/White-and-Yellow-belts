#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> A(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  std::sort(A.begin(), A.end(), [](int x, int y) {
    return std::abs(x) < std::abs(y);
  });
  for (size_t i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << std::endl;
}