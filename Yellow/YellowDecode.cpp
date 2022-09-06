#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  q.stops.clear();
  std::string query;
  is >> query;
  if (query == "NEW_BUS") {
    q.type = QueryType::NewBus;
    int number_of_stops = 0;
    is >> q.bus;
    is >> number_of_stops;
    for (int i = 0; i < number_of_stops; ++i) {
      is >> query;
      q.stops.push_back(query);
    }
  } else if (query == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (query == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (query == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse {
  std::string stop;
  std::map<std::string, std::vector<std::string>> stops_to_buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.stops_to_buses.count(r.stop) == 0) {
    os << "No stop";
  } else {
    for (const std::string& bus : r.stops_to_buses.at(r.stop)) {
      os << bus << " ";
    }
  }
  return os;
}

struct StopsForBusResponse {
  std::string bus;
  std::map<std::string, std::vector<std::string>> buses_to_stops;
  std::map<std::string, std::vector<std::string>> stops_to_buses;
};

ostream& operator<< (ostream& os, const StopsForBusResponse& r) {
  if (r.buses_to_stops.count(r.bus) == 0) {
    os << "No bus";
  } else {
    int i = 0;
    for (const string& stop : r.buses_to_stops.at(r.bus)) {
      os << "Stop " << stop << ": ";
      if (r.stops_to_buses.at(stop).size() == 1) {
        os << "no interchange";
      } else {
        for (const string& other_bus : r.stops_to_buses.at(stop)) {
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

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  if (r.buses_to_stops.empty()) {
    os << "No buses";
  } else {
    int i = 0;
    for (const auto& bus_item : r.buses_to_stops) {
      os << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second) {
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

class BusManager {
  map<string, vector<string>> buses_to_stops;
  map<string, vector<string>> stops_to_buses;
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    vector<string>& new_stops = buses_to_stops[bus];
    new_stops.resize(0);
    for (const string& stop : stops) {
      new_stops.push_back(stop);
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    return {stop, stops_to_buses};
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    return {bus, buses_to_stops, stops_to_buses};
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }
};


int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}