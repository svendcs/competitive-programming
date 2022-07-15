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
  std::vector<int> digits;
  int a;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a;
    digits.push_back(a);
  }

  int m;
  std::string moves;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> m >> moves;
    for (char move : moves) {
      if (move == 'U') {
        digits[i]--;
        if (digits[i] == -1)
          digits[i] = 9;
      }
      else {
        digits[i]++;
        if (digits[i] == 10)
          digits[i] = 0;
      }
    }
  }

  for (size_t i = 0; i < n; ++i) {
    std::cout << digits[i];
    if (i + 1 < n)
      std::cout << " ";
  }
  std::cout << "\n";
}

int main() {
  int problemCount;
  scanf("%d", &problemCount);

  int n;
  for (size_t i = 0; i < problemCount; ++i) {
    std::cin >> n;

    std::cout << handleProblem(n) << std::endl;
  }
}

