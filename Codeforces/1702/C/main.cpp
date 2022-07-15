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

typedef std::unordered_map<int, size_t, custom_hash> MapType;
bool canTravel(const MapType &minIndices, const MapType &maxIndices, int from, int to) {
  auto fromIt = minIndices.find(from);
  auto toIt = maxIndices.find(to);
  if (fromIt == minIndices.end())
    return false;
  if (toIt == maxIndices.end())
    return false;

  return fromIt->second <= toIt->second;
}

void handleRoute(int length, int queries) {
  MapType minIndices;
  MapType maxIndices;
  int a;
  for (size_t i = 0; i < length; ++i) {
    scanf("%d", &a);

    maxIndices[a] = i;
    if (minIndices.find(a) == minIndices.end())
      minIndices[a] = i;
  }

  int from, to;
  for (size_t i = 0; i < queries; ++i) {
    scanf("%d %d", &from, &to);
    if (canTravel(minIndices, maxIndices, from, to))
      printf("YES\n");
    else
      printf("NO\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int length;
  int queries;
  for (size_t i = 0; i < n; ++i) {
    scanf("%d %d", &length, &queries);

    handleRoute(length, queries);
  }
}

