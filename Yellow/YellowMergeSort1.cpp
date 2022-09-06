#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }
  std::vector<typename RandomIt::value_type> vec(range_begin, range_end);
  RandomIt mid = (vec.end() - vec.begin())/2 + vec.begin();
  MergeSort(vec.begin(), mid);
  MergeSort(mid, vec.end());
  std::merge(vec.begin(), mid, mid, vec.end(), range_begin);
}

int main() {
  std::vector<int> test = {6, 4, 7, 6, 4, 4, 0, 1};
  for (const auto& el : test) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  MergeSort(test.begin(), test.end());
  for (const auto& el : test) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}