#include <iostream>

int main() {
  int x, y, z, n = 0;
  int r = 0;
  uint64_t volume = 1;
  uint64_t mass = 0;
  std::cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    std::cin >> x >> y >> z;
    volume = volume * x;
    volume = volume * y;
    volume = volume * z;
    mass += volume * r;
    volume = 1;
  }
  std::cout << mass << std::endl;
}