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

bool canTwoColor(int i, int color, std::vector<int> &colors, std::vector<std::pair<int, int>> &dominoes, std::unordered_map<int, std::vector<int>, custom_hash> &edges) {
  if (colors[i] != -1) {
    return colors[i] == color;
  }

  // std::cout << i << " " << color << " " << std::endl;

  int a = dominoes[i].first;
  int b = dominoes[i].second;
  colors[i] = color;
  for (int neighbor : edges[a]) {
      if (neighbor == i)
        continue;
      if (!canTwoColor(neighbor, color == 0 ? 1 : 0, colors, dominoes, edges))
        return false;
  }
  for (int neighbor : edges[b]) {
      if (neighbor == i)
        continue;
      if (!canTwoColor(neighbor, color == 0 ? 1 : 0, colors, dominoes, edges))
        return false;
  }
  // std::cout << "done" << std::endl;

  return true;
}

bool handleProblem(int n) {
  std::vector<std::pair<int, int>> dominoes;
  std::unordered_map<int, std::vector<int>, custom_hash> edges;

  int a, b;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a, &b);

    dominoes.emplace_back(a, b);
    edges[a].push_back(i);
    edges[b].push_back(i);
  }

  for (auto p : dominoes) {
    if (p.first == p.second)
      return false;
  }

  std::vector<int> colors(n, -1);
  for (size_t i = 0; i < n; ++i) {
    if (colors[i] != -1)
      continue;
    if (!canTwoColor(i, 0, colors, dominoes, edges))
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

