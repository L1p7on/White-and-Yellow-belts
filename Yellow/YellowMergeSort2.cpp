#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 3) {
    return;
  }
  std::vector<typename RandomIt::value_type> vec(range_begin, range_end);
  RandomIt one_third = vec.begin() + (vec.end() - vec.begin())/3;
  RandomIt two_third = vec.begin() + 2 * (vec.end() - vec.begin()) / 3;
  MergeSort(vec.begin(), one_third);
  MergeSort(one_third, two_third);
  MergeSort(two_third, vec.end());
  std::vector<typename RandomIt::value_type> tmp;
  std::merge(vec.begin(), one_third, one_third, two_third, std::back_inserter(tmp));
  std::merge(tmp.begin(), tmp.end(), two_third, vec.end(), range_begin);
}

int main() {
  std::vector<int> test = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  for (const auto& el : test) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  // std::vector<int> tmp;
  // std::merge(test.begin(), test.begin() + 5, test.begin() + 5, test.end(), std::back_inserter(tmp));
  MergeSort(test.begin(), test.end());
  for (const auto& el : test) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}