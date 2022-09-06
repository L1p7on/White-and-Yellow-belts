#include <iostream>

int main() {
  int A, B;
  std::cin >> A;
  std::cin >> B;
  if (A % 2 == 1) {
    A++;
  }
  for (int i = A; i <= B; i+=2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}