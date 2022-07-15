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

bool handleProblem(int n) {
  // std::cout << "Solving size " << n << std::endl;
  std::multiset<int> a;
  std::vector<int> b;

  int num;
  for (size_t i = 0; i < n; ++i) {
    scanf("%d", &num);
    while (num % 2 == 0)
      num /= 2;
    a.insert(num);
  }

  for (size_t i = 0; i < n; ++i) {
    scanf("%d", &num);
    b.push_back(num);
  }

  for (auto num : b) {
    // std::cout << "Trying to find " << num << std::endl;
    while (num % 2 == 0)
      num /= 2;

    bool foundMatch = false;
    while (true) {
      // std::cout << "Trying " << num << std::endl;
      auto it = a.find(num);
      if (it != a.end()) {
        a.erase(it);
        foundMatch = true;
        // std::cout << "Found match " << num << std::endl;
        break;
      }

      if (num == 1)
        break;
      num /= 2;
    }

    if (!foundMatch)
      return false;
  }

  return true;
}

int main() {
  int problemCount;
  scanf("%d", &problemCount);

  int n;
  for (size_t i = 0; i < problemCount; ++i) {
    scanf("%d", &n);

    if (handleProblem(n))
      printf("YES\n");
    else
      printf("NO\n");
  }
}

