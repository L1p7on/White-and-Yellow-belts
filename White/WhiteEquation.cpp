#include <iostream>
#include <cmath>
int main() {
  double a, b, c;
  double result = 0.0;
  std::cin >> a >> b >> c;
  if (std::fabs(a) < 10e-14) {
    if (std::fabs(b) > 10e-14) {
      result = -(c*1.0/b);
      std::cout << result << std::endl;
    }
  } else {
    if (b*b - 4*c*a < 0) {
      return -1;
    }
    if (std::sqrt(b*b - 4*c*a) < 10e-14) {
      result = (-b - std::sqrt(b*b - 4*a*c))/ (2*a);
      std::cout << result << std::endl;
    } else {
      result = (-b - std::sqrt(b*b - 4*a*c))/ (2*a);
      std::cout << result << " ";
      result = (-b + std::sqrt(b*b - 4*a*c))/ (2*a);
      std::cout << result << std::endl;
    }
  }
}