#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
  int tmp = 0;
  for (size_t i = 0; i < v.size()/2; ++i) {
    tmp = v[i];
    v[i] = v[v.size() - 1 - i];
    v[v.size() - 1 - i] = tmp;
  }
}

int main() {
  std::vector<int> v = {5, 3, 6};
  Reverse(v);
  std::cout << v[0] << " " << v[1] << " " << v[2] << std::endl;
}