#include "responses.h"

std::ostream& operator<< (std::ostream& os, const BusesForStopResponse& r) {
  if (r.stops_to_buses.count(r.stop) == 0) {
    os << "No stop";
  } else {
    for (const std::string& bus : r.stops_to_buses.at(r.stop)) {
      os << bus << " ";
    }
  }
  return os;
}

std::ostream& operator<< (std::ostream& os, const StopsForBusResponse& r) {
  if (r.buses_to_stops.count(r.bus) == 0) {
    os << "No bus";
  } else {
    int i = 0;
    for (const std::string& stop : r.buses_to_stops.at(r.bus)) {
      os << "Stop " << stop << ": ";
      if (r.stops_to_buses.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        for (const std::string& other_bus : r.stops_to_buses.at(stop)) {
          if (r.bus != other_bus) {
            os << other_bus << " ";
          }
        }
      }
      if (i + 1 != r.buses_to_stops.at(r.bus).size()) {
        os << std::endl;
      }
      ++i;
    }
  }
  return os;
}

std::ostream& operator<< (std::ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
    os << "No buses";
  } else {
    int i = 0;
    for (const auto& bus_item : r.buses_to_stops) {
      os << "Bus " << bus_item.first << ": ";
      for (const std::string& stop : bus_item.second) {
        os << stop << " ";
      }
      if (i + 1 != r.buses_to_stops.size()) {
        os << std::endl;
      }
      ++i;
    }
  }
  return os;
}