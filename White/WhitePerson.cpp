#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

std::string FindFullNameHistory(const std::vector<std::pair<int, std::string>>& first_names, int year) {
  int copy_year = 0;
  std::string first_name, result1, copy;
  for (int i = 0; i <= first_names.size(); ++i) {
    if (i < first_names.size() && year >= first_names[i].first) {
      first_name = first_names[i].second;
      copy_year = first_names[i].first;
    } else {
      copy = first_name;
      --i;
      for (; i >= 0; --i) {
        if (copy != first_names[i].second && copy_year != first_names[i].first) {
          result1 += first_names[i].second;
          if (i != 0) {
            result1 += ", ";
          }
          copy = first_names[i].second;
          copy_year = first_names[i].first;
        }
      }
      break;
    }
  }
  if (first_name.empty()) {
    return first_name;
  } else if (result1.empty()) {
    return first_name;
  }
  return first_name + " (" + result1 + ")";
}

class Person {
public:
  Person(const std::string& first_name, const std::string last_name, int year) :
  first_names(),
  last_names(),
  year_of_birth(year) {
    first_names.push_back(std::make_pair(year, first_name));
    last_names.push_back(std::make_pair(year, last_name));
  }
  void ChangeFirstName(int year, const std::string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (year >= this->year_of_birth) {
      auto lower = std::lower_bound(this->first_names.begin(), this->first_names.end(),
      year, [](const std::pair<int, std::string>& x, const int y) {
        return (x.first < y);
      });
      if (!first_names.empty() && lower != first_names.end() &&
      lower->first == year) {
        for (; lower < first_names.end(); ++lower) {
          if (lower->first != year) {
            break;
          }
        }
        this->first_names.insert(lower, std::make_pair(year, first_name));
      } else {
      this->first_names.insert(lower, std::make_pair(year, first_name));
      }
    }
  }
  void ChangeLastName(int year, const std::string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (year >= this->year_of_birth) {
      auto lower = std::lower_bound(this->last_names.begin(), this->last_names.end(),
      year, [](const std::pair<int, std::string>& x, const int y) {
        return x.first < y;
      });
      if (!last_names.empty() && lower != last_names.end() &&
      lower->first == year) {
        for (; lower < last_names.end(); ++lower) {
          if (lower->first != year) {
            break;
          }
        }
        this->last_names.insert(lower, std::make_pair(year, last_name));
      } else {
      this->last_names.insert(lower, std::make_pair(year, last_name));
      }
    }
  }
  std::string GetFullName(int year) const {
    // получить имя и фамилию по состоянию на конец года year
    std::string first_name, last_name;
    auto lower_name = std::lower_bound(this->first_names.begin(), this->first_names.end(),
    year, [](const std::pair<int, std::string>& x, const int y) {
      return (x.first < y);
    });
    auto lower_last_name = std::lower_bound(this->last_names.begin(), this->last_names.end(),
    year, [](const std::pair<int, std::string>& x, const int y) {
      return x.first < y;
    });
    if (!first_names.empty() && lower_name->first == year) {
      first_name = lower_name->second;
    } else if (!first_names.empty() && lower_name > first_names.begin()) {
      first_name = (lower_name - 1)->second;
    }
    if (!last_names.empty() && lower_last_name->first == year) {
      last_name = lower_last_name->second;
    } else if (!last_names.empty() && lower_last_name > last_names.begin()) {
      last_name = (lower_last_name - 1)->second;
    }
    if (first_name.empty() && last_name.empty()) {
      return "No person";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    }
    return first_name + " " + last_name;
  }
  std::string GetFullNameWithHistory(int year) const {
    // получить все имена и фамилии по состоянию на конец года year
    std::string first_name, last_name;
    first_name = FindFullNameHistory(first_names, year);
    last_name = FindFullNameHistory(last_names, year);
    if (first_name.empty() && last_name.empty()) {
      return "No person";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    }
    return first_name + " " + last_name;
  }
public:
  // приватные поля
  std::vector<std::pair<int, std::string>> first_names;
  std::vector<std::pair<int, std::string>> last_names;
  int year_of_birth;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1961, "Ivanova");
  person.ChangeFirstName(1964, "Polina");
  person.ChangeLastName(1961, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
