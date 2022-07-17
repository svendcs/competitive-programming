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

using namespace std;

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

long long handleProblem(int n) {
  std::vector<int> elements(n);
  std::vector<long long> suffixSum(n+2, 0);

  for (size_t i = 0; i < n; ++i) {
    std::cin >> elements[i];
  }

  long long res = 0;
  for (int i = n; i >= 1; --i) {
    suffixSum[i] += suffixSum[i+1];

    const auto el = elements[i-1];
    if (el >= i)
      continue;

    // cout << "Found element. index=" << i << "; el=" << el << endl;

    res += suffixSum[i+1];

    suffixSum[el]++;
  }

  return res;
}

int main() {
  int problemCount;
  cin >> problemCount;

  int n;
  for (size_t i = 0; i < problemCount; ++i) {
    cin >> n;
    cout << handleProblem(n) << endl;
  }
}

