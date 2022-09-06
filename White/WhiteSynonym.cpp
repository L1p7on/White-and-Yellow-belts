#include <iostream>
#include <set>
#include <map>

int main() {
  std::map<std::string, std::set<std::string>> words;
  size_t number_of_operations = 0;
  std::cin >> number_of_operations;
  std::string operation;
  std::string word1;
  std::string word2;
  for (size_t i = 0; i < number_of_operations; ++i) {
    std::cin >> operation;
    if (operation == "ADD") {
      std::cin >> word1;
      std::cin >> word2;
      words[word1].insert(word2);
      words[word2].insert(word1);
    } else if (operation == "COUNT") {
      std::cin >> word1;
      std::cout << words[word1].size() << std::endl; // Is it okay to create empty set of synonyms of word,
                                                     //  which probably didn't exist in our map before words[word1]?
    } else if (operation == "CHECK") {
      std::cin >> word1;
      std::cin >> word2;
      if (words[word1].find(word2) != words[word1].end()) {
        std::cout << "YES" << std::endl;
      } else if (words[word2].find(word1) != words[word2].end()) {
        std::cout << "YES" << std::endl;
      } else {
        std::cout << "NO" << std::endl;
      }
    }
  }
}