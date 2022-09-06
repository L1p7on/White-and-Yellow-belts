#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
  std::vector<std::string>& new_stops = buses_to_stops[bus];
    new_stops.resize(0);
    for (const std::string& stop : stops) {
      new_stops.push_back(stop);
      stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
  return {stop, stops_to_buses};
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
  return {bus, buses_to_stops, stops_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
  return {buses_to_stops};
}