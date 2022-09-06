#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
  std::ifstream input("input.txt");
  double a = 0.0;
  while (input >> a) {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << a << std::endl;
  }
}