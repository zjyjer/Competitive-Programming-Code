#include <iostream>

int main() {
  int x, y, z;
  while (std::cin >> x >> y >> z) {
    int score = x * 3 + y * 2 + z * 6;
    std::cout << (score >= 60 ? "I passed the exam." : "Exam was too hard.") << std::endl;
    std::cout << score << std::endl;
  }
  return 0;
}
