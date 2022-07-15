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
#include <stdio.h>
#include <chrono>
#include <set>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void handleProblem(int n) {
  std::unordered_set<std::string> stringsSet;
  std::vector<std::string> strings;
  std::vector<bool> res;

  std::string str;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> str;

    strings.push_back(str);
    stringsSet.insert(str);
  }

  for (const auto &str : strings) {
    if (str.size() == 1) {
      res.push_back(false);
      continue;
    }

    bool found = false;
    for (size_t i = 1; i < str.size(); ++i) {
      const auto a  = str.substr(0, i);
      const auto b  = str.substr(i, str.size());

      // std::cout << "Testing " << a << " " << b << std::endl;

      if (stringsSet.find(a) != stringsSet.end() && stringsSet.find(b) != stringsSet.end()) {
        found = true;
        break;
      }
    }

    res.push_back(found);
  }

  for (bool b : res)
    std::cout << b;
  std::cout << std::endl;
}

int main() {
  int problemCount;
  scanf("%d", &problemCount);

  int n;
  for (size_t i = 0; i < problemCount; ++i) {
    std::cin >> n;

    handleProblem(n);
  }
}

