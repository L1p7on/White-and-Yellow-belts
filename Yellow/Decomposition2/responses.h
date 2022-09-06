#ifndef INCLUDE_RESPONSEC_H_
#define INCLUDE_RESPONSEC_H_
#include <vector>
#include <string>
#include <iostream>
#include <map>

struct BusesForStopResponse {
  std::string stop;
  std::map<std::string, std::vector<std::string>> stops_to_buses;
};

std::ostream& operator<< (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  std::string bus;
  std::map<std::string, std::vector<std::string>> buses_to_stops;
  std::map<std::string, std::vector<std::string>> stops_to_buses;
};

std::ostream& operator<< (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator<< (std::ostream& os, const AllBusesResponse& r);

#endif // INCLUDE_RESPONSEC_H_