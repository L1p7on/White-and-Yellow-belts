#include <iostream>
#include <vector>

int main() {
  int N = 0;
  int64_t avg = 0;
  size_t K = 0;
  std::cin >> N;
  std::vector<int> temperature(N);
  for (size_t i = 0; i < temperature.size(); ++i) {
    std::cin >> temperature[i];
  }
  for (size_t i = 0; i < temperature.size(); ++i) {
    avg += temperature[i];
  }
  avg /= N;
  avg = static_cast<int>(avg);
  for (size_t i = 0; i < temperature.size(); ++i) {
    if (temperature[i] > avg) {
      ++K;
    }
  }
  std::cout << K << std::endl;
  for (size_t i = 0; i < temperature.size(); ++i) {
    if (temperature[i] > avg) {
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;
}