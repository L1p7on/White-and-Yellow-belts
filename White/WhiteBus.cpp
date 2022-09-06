#include <iostream>
#include <map>
#include <vector>

int main() {
  size_t n = 0;
  std::cin >> n;
  std::string input_command = "";
  size_t number_of_stops = 0;
  std::string bus_name = "";
  std::string stop_name = "";
  std::map<std::string, std::vector<std::string>> buses;
  std::map<std::string, std::vector<std::string>> stops;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> input_command;
    if (input_command == "NEW_BUS") {
      std::cin >> bus_name;
      std::cin >> number_of_stops;
      for (size_t j = 0; j < number_of_stops; ++j) {
        std::cin >> stop_name;
        buses[bus_name].push_back(stop_name);
        stops[stop_name].push_back(bus_name);
      }
    } else if (input_command == "BUSES_FOR_STOP") {
      std::cin >> stop_name;
      if (stops.count(stop_name) == 0) {
        std::cout << "No stop" << std::endl;
      } else {
        for (auto bus : stops[stop_name]) {
          std::cout << bus << " ";
        }
        std::cout << std::endl;
      }
    } else if (input_command == "STOPS_FOR_BUS") {
      std::cin >> bus_name;
      if (buses.count(bus_name) == 0) {
        std::cout << "No bus" << std::endl;
      } else {
        for (auto el : buses[bus_name]) {
          std::cout << "Stop " << el << ": ";
          if (stops[el].size() == 1) {
            std::cout << "no interchange" << std::endl;
          } else {
            for (auto bus : stops[el]) {
              if (bus == bus_name) {
                continue;
              }
              std::cout << bus << " ";
            }
            std::cout << std::endl;
          }
        }
      }
    } else if (input_command == "ALL_BUSES") {
      if (buses.empty()) {
        std::cout << "No buses" << std::endl;
      } else {
        for (auto [key, value] : buses) {
          std::cout << "Bus " << key << ": ";
          for (auto el : value) {
            std::cout << el << " ";
          }
          std::cout << std::endl;
        }
      }
    }
  }
}