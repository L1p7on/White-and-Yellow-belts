#include <iostream>
#include <string>

int main() {
  int n = 0;
  std::cin >> n;
  int number_of_operations = 0;
  std::cin >> number_of_operations;
  std::string result = std::to_string(n);
  std::string operation;
  std::string number;
  std::string last_operation;
  for (int i = 0; i < number_of_operations; ++i) {
    std::cin >> operation;
    std::cin >> number;
    if (last_operation == "-" && operation == "*" ||
        last_operation == "+" && operation == "*" ||
        last_operation == "-" && operation == "/" ||
        last_operation == "+" && operation == "/") {
          result.insert(result.begin(), '(');
          result.insert(result.end(), ')');
        }
    result += " ";
    result += operation;
    result += " ";
    result += number;
    last_operation = operation;
  }
  std::cout << result << std::endl;
}