#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s) {
  std::vector<std::string> result;
  auto word_begin = s.begin();
  auto word_end = s.begin();
  while (word_begin != s.end()) {
    word_end = std::find_if(++word_end, s.end(), [](const char c) {
      return c == ' ';
    });
    if (*word_begin == ' ') {
      ++word_begin;
    } // eto o4en' ploho
    result.push_back(std::string(word_begin, word_end));
    word_begin = word_end;
  }
  return result;
}

int main() {
  std::string s = "hello dude nice to meet you";
  std::vector<std::string> A = SplitIntoWords(s);
  for (const auto& el : A) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
}