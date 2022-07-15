#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

std::string deleteLetters(const std::string &input, size_t target) {
  std::deque<std::pair<char, size_t>> letters;
  size_t totalCost = 0;

  for (size_t i = 0; i < input.size(); ++i) {
    letters.emplace_back(input[i], i);
    totalCost += input[i] + 1 - 'a';
  }

  std::sort(letters.begin(), letters.end(), [](const auto &a, const auto &b) { return a.first > b.first; });

  while (totalCost > target) {
    const char c = letters.front().first;
    totalCost -= c + 1 - 'a';
    letters.pop_front();
  }

  std::sort(letters.begin(), letters.end(), [](const auto &a, const auto &b) { return a.second < b.second; });

  std::string result;
  for (auto p : letters) {
    result.push_back(p.first);
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;

  std::string str;
  int target;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> str >> target;
    std::cout << deleteLetters(str, target) << std::endl;
  }
}
