#include <iostream>
#include <algorithm>
#include "phone_number.h"

PhoneNumber::PhoneNumber(const string &international_number) :
  country_code_(),
  city_code_(),
  local_number_() {
    if (international_number.empty()) {
      throw std::invalid_argument("empty input");
    }
    if (std::count(international_number.begin(), international_number.end(), '-') < 2) {
      throw std::invalid_argument("not enough -");
    }
    if (international_number[0] != '+') {
      throw std::invalid_argument("doesn't have +");
    }
    int first = international_number.find_first_of('-');
    int delta = international_number.find_first_of('-', first + 1) - first;
    country_code_ = international_number.substr(1, first - 1);
    city_code_ = international_number.substr(first + 1, delta - 1);
    local_number_ = international_number.substr(first + delta + 1);
    if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
      throw std::invalid_argument("empty section");
    }
}

std::string PhoneNumber::GetCountryCode() const {
  return country_code_;
}

std::string PhoneNumber::GetCityCode() const {
  return city_code_;
}

std::string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}

std::string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}

// int main() {
//   try {
//     PhoneNumber A("+1-2-coursera-cpp");
//     std::cout << A.GetInternationalNumber() << std::endl;
//     std::cout << A.GetCountryCode() << std::endl;
//     std::cout << A.GetCityCode() << std::endl;
//     std::cout << A.GetLocalNumber() << std::endl;
//   } catch (std::invalid_argument e) {
//     std::cout << e.what() << std::endl;
//   }
// }