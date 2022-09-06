#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

enum class Lang {
  DE, FR, IT
};

struct Region {
  std::string std_name;
  std::string parent_std_name;
  std::map<Lang, std::string> names;
  int64_t population;
};

int FindMaxRepetitionCount(const std::vector<Region>& regions);
bool operator<(const Region& lhs, const Region& rhs) {
  auto lhs_key = std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
  auto rhs_key = std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
  return lhs_key < rhs_key;
}

int main() {
  Region one = {"Moscow", "Russia", {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}}, 89};
  Region two = {"Moscow", "Russia", {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}}, 89};
  Region three = {"Moscow", "Russia", {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Moscal"}}, 89};
  std::vector<Region> regions = {one, two, three};
  // std::cout << (one.names == two.names) << std::endl;
  std::cout << FindMaxRepetitionCount(regions) << std::endl;
}

int FindMaxRepetitionCount(const std::vector<Region>& regions) {
  if (regions.empty()) {
    return 0;
  }
  int repeats = 1;
  int k = 0;
  std::map<Region, int> map;
  for (auto& el : regions) {
    ++map[el];
    if (map[el] > repeats) {
      repeats = map[el];
    }
  }
  return repeats;
}