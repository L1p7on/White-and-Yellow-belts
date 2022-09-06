#include <iostream>
#include <vector>
int main() {
  int x = 0;
  std::vector<int> result(32);
  std::cin >> x;
  for (int i = 31; i >= 0; --i) {
    result[i] = (int)((x>>i)&1);
  }
  for (int i = 31; i >= 0; --i) {
    if (result[i] != 0) {
      for (; i >= 0; --i) {
        std::cout << result[i];
      }
      std::cout << std::endl;
      break;
    }
  }
}