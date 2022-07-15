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

int getPrice(int number) {
  int newPrice = 1;
  while (newPrice <= number)
    newPrice *= 10;
  return newPrice /= 10;
}

int main() {
  int n;
  std::cin >> n;

  for (size_t i = 0; i < n; ++i) {
    int a; std::cin >> a;
    std::cout << a - getPrice(a) << std::endl;
  }
}
