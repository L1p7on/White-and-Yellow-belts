#include "sum_reverse_sort.h"
#include <algorithm>
// #include <iostream>

int Sum(int x, int y) {
  return x + y;
}

string Reverse(string s) {
  char tmp = 'a';
  for (size_t i = 0; i < s.size()/2; ++i) {
    tmp = s[i];
    s[i] = s[s.size() - i - 1];
    s[s.size() - i - 1] = tmp;
  }
  return s;
}

void Sort(vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
}

// int main() {
//   std::vector<int> A = {1, 4, 3, 2};
//   std::string s = "abc";
//   std::cout << Sum(5, 3) << std::endl;
//   std::cout << Reverse(s) << std::endl;
//   Sort(A);
//   for (const auto& el : A) {
//     std::cout << el << " ";
//   }
//   std::cout << endl;
// }