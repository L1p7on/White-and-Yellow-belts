#include <iostream>
#include <vector>

int numberOfDays(int month) {
  if (month % 12 == 2) {
    return 28;
  }
  if (month % 12 == 0) {
    return 31;
  }
  if (month % 12 < 8) {
    if (month % 2 == 1) {
      return 31;
    } else {
      return 30;
    }
  } else {
    if (month % 2 == 0) {
      return 31;
    } else {
      return 30;
    }
  }
}
int main() {
  std::vector<std::vector<std::string>> calendar(31); // First Month is January
  int number_of_operations = 0;
  int day = 0;
  int month = 1;
  std::string operation;
  std::cin >> number_of_operations;
  for (int i = 0; i < number_of_operations; ++i) {
    std::cin >> operation;
    if (operation == "ADD") {
      std::cin >> day;
      std::cin >> operation;
      calendar[day-1].push_back(operation);
    } else if (operation == "DUMP") {
      std::cin >> day;
      std::cout << calendar[day-1].size() << " ";
      for (const auto& doings : calendar[day-1]) {
        std::cout << doings << " ";
      }
      std::cout << std::endl;
    } else if (operation == "NEXT") {
      if (calendar.size() <= numberOfDays(month+1)) {
        calendar.resize(numberOfDays(month+1));
      } else {
        for (int j = numberOfDays(month+1); j < calendar.size(); ++j) {
          // std::cout << j << std::endl;
          // for (auto k = calendar[j].begin(); k < calendar[j].end(); ++k) {
          //   std::cout << *k << " ";
          // }
          calendar[numberOfDays(month+1) - 1].insert(calendar[numberOfDays(month+1) - 1].end(),
                                                 calendar[j].begin(), calendar[j].end());
        }
        calendar.resize(numberOfDays(month + 1));
      }
      ++month;
    }
  }
}