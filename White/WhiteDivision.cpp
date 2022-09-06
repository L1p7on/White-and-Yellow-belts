#include <iostream>

int main() {
  int a,b;
  std::cin >> a;
  std::cin >> b;
  if (b == 0) {
    std::cout << "Impossible" << std::endl;
  } else {
    std::cout << a/b << std::endl;
  }
}