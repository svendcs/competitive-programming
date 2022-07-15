#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

int getDays(const std::string &str) {
  int days = 1;

  std::unordered_set<char> memory;
  for (char c : str) {
    if (memory.size() < 3 || memory.find(c) != memory.end()) {
      memory.insert(c);
      continue;
    }

    memory.clear();
    memory.insert(c);
    days++;
  }

  return days;
}

int main() {
  int n;
  std::cin >> n;

  std::string str;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> str;
    std::cout << getDays(str) << std::endl;
  }
}
