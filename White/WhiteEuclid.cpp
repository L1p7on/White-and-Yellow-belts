#include <iostream>
int Euclid(int a, int b); // b < a

int main() {
  int a, b;
  std::cin >> a >> b;
  if (a < b) {
    std::cout << Euclid(b, a) << std::endl;
  } else {
    std::cout << Euclid(a, b) << std::endl;
  }
}

int Euclid(int a, int b) {
  if (a == b) {
    return a;
  }
  int delta = a/b;
  if (a == delta * b) {
    return b;
  }
  a -= delta * b;
  return Euclid(b, a);
}