#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
  std::map<std::vector<std::string>, size_t> buses;
  std::vector<std::string> stops;
  std::string stop_name;
  size_t number_of_stops = 0;
  size_t number_of_operations = 0;
  size_t number_of_buses = 0;
  std::cin >> number_of_operations;
  for (size_t i = 0; i < number_of_operations; ++i) {
    std::cin >> number_of_stops;
    for (size_t j = 0; j < number_of_stops; ++j) {
      std::cin >> stop_name;
      stops.push_back(stop_name);
    }
    if (buses.count(stops) == 0) {
      ++number_of_buses;
      buses[stops] = number_of_buses;
      std::cout << "New bus " << number_of_buses << std::endl;
    } else {
      std::cout << "Already exists for " << buses[stops] << std::endl;
    }
    stops.clear();
  }
}