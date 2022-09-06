#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
  auto it = std::find_if(elements.begin(), elements.end(), [border](const T& x) {
    return x > border;
  });
  std::vector<T> result;
  while (it != elements.end()) {
    result.push_back(*it);
    it = std::find_if(++it, elements.end(), [border](const T& x) {
      return x > border;
    });
  }
  return result;
}

int main() {
  std::set<int> A = {1, 4, 7, 5};
  for (const int el : A) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::vector<int> B = FindGreaterElements<int>(A, 3);
  for (const int el : B) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  
  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
  return 0;
}