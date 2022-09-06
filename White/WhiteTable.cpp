#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

int main() {
  std::ifstream in("input.txt");
  int N = 0;
  int M = 0;
  in >> N >> M;
  int a;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      in >> a;
      in.ignore(1);
      std::cout << std::setw(10) << a;
      if (j+1 < M) {
        std::cout << " ";
      }
    }
    if (i+1 < N) {
      std::cout << std::endl;
    }
  }
}