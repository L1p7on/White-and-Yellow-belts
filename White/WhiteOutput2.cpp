#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream input("input.txt");
  std::ofstream output("output.txt");
  std::string s;
  while (getline(input, s)) {
    output << s << std::endl;
  }
}