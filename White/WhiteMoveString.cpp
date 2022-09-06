#include <iostream>
#include <string>
#include <vector>

void MoveStrings(std::vector<std::string>& source,
                 std::vector<std::string>& destination) {
  for (size_t i = 0; i < source.size(); ++i) {
    destination.push_back(source[i]);
  }
  source.clear();
}

// int main() {
//   std::vector<std::string> s = {"a", "b", "c"};
//   std::vector<std::string> d = {"1", "2", "3"};
//   MoveStrings(s, d);
//   std::cout << s.size() << " " << d[5] << std::endl;
// }