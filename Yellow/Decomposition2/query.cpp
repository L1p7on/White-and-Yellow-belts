#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
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