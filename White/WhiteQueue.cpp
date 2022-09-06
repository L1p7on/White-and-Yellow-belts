#include <iostream>
#include <vector>
#include <utility>
#include <string>
int main() {
  std::vector<int> queue;
  std::string input = "";
  size_t operations = 0;
  int number_of_people = 0;
  std::cin >> operations;
  for (size_t i = 0; i < operations; ++i) {
    std::cin >> input;
    if (input == "COME") {
      std::cin >> number_of_people;
      if (number_of_people < 0) {
        for (; number_of_people < 0; ++number_of_people) {
          queue.pop_back();
        }
      } else {
        for (size_t j = 0; j < number_of_people; ++j) {
         
        }
      }
    } else if (input == "WORRY") {
      std::cin >> number_of_people;
      ++queue[number_of_people];
    } else if (input == "QUIET") {
      std::cin >> number_of_people;
      if (queue[number_of_people] > 1) {
        --queue[number_of_people];
      }
    } else if (input == "WORRY_COUNT") {
      number_of_people = 0;
      for (auto el : queue) {
        number_of_people += el;
      }
      number_of_people -= queue.size();
      std::cout << number_of_people << std::endl;
    }
  }
}