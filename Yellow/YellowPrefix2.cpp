#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end,
                                             const std::string& prefix) {
  size_t size_of_prefix = prefix.size();
  RandomIt left = std::lower_bound(range_begin, range_end, prefix, [size_of_prefix](const std::string& s, const std::string& prefix) {
    return s.substr(0, size_of_prefix) < prefix;
  });
  RandomIt right = std::upper_bound(range_begin, range_end, prefix, [size_of_prefix](const std::string& prefix, const std::string& s) {
    return s.substr(0, size_of_prefix) > prefix;
  });
  // if (left != right) {
  //   --right;
  // }
  return std::make_pair(left, right);
}

int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}