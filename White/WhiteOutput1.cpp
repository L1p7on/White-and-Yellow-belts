#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string s;
  std::ifstream input("input.txt");
  while (getline(input, s)) {
    std::cout << s << std::endl;
  }
}