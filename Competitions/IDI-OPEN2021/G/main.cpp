#include <iostream>
#include <vector>

static constexpr size_t SIZE = 4520;
static constexpr size_t OFFSET = 2250;

static constexpr size_t get_pos(const int x, const int y) {
  return (OFFSET + y+1) * SIZE + (OFFSET + x+1);
}

int main() {
  int r, q;
  std::cin >> r >> q;

  std::vector<long long> horizontal_lines(SIZE*SIZE+42, 0);
  std::vector<long long> vertical_lines(SIZE*SIZE+42, 0);

  // Process robots
  for (size_t i = 0; i < r; ++i) {
    int x, y, w, h, c;
    std::cin >> x >> y >> w >> h >> c;
    // std::cout << "Processing query " << x << " " << y << " " << w << " " << h << " " << c << std::endl;

    // First vertical line
    vertical_lines[get_pos(x, y)] += c;
    vertical_lines[get_pos(x, y+h)] -= c;

    // Second vertical line
    vertical_lines[get_pos(x+w, y)] += c;
    vertical_lines[get_pos(x+w, y+h)] -= c;


    // First horizontal
    horizontal_lines[get_pos(x, y)] += c;
    horizontal_lines[get_pos(x+w, y)] -= c;

    // Second horizontal
    horizontal_lines[get_pos(x, y+h)] += c;
    horizontal_lines[get_pos(x+w, y+h)] -= c;
  }

  // 1  0 0               | 0 0
  // 0  0 0               | 0 0
  // -1 0 0               0 0 0

  // 1 0 0
  // 1 0 0
  // 0 0 0

  // 1 1 1
  // 2 2 2      c_xy : sum of values x',y' <= xy
  // 0 0 0


  // Compute vertical prefix sums
  for (int x = -2250; x <= 2250 + 5; ++x) {
    long long current = 0;
    long long sum_above = 0;
    for (int y = -2250; y <= 2250 + 5; ++y) {
      current += vertical_lines[get_pos(x, y)];
      sum_above += current;
      vertical_lines[get_pos(x, y)] = sum_above + vertical_lines[get_pos(x-1,y)];
      // vertical_lines[get_pos(x, y)] = current;
    }
  }

  // Compute horizontal lines
  for (int y = -2250; y <= 2250 + 5; ++y) {
    long long current = 0;
    long long sum_left = 0;
    for (int x = -2250; x <= 2250 + 5; ++x) {
      current += horizontal_lines[get_pos(x, y)];
      sum_left += current;
      horizontal_lines[get_pos(x, y)] = sum_left + horizontal_lines[get_pos(x, y-1)];
      // horizontal_lines[get_pos(x, y)] = current;
    }
  }

  // 0 1 1
  // 0 1 1    (2, 2)     (0,2)
  // 0 1 1 ()

  // std::cout << "Horizontal lines" << std::endl;
  // for (int y = -2; y <= 7; ++y) {
  //   std::cout << y << ": ";
  //   for (int x = -2; x <= 7; ++x) {
  //     std::cout << vertical_lines[get_pos(x, y)] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // std::cout << "Answers"  << std::endl;

  // Answer queries
  for (size_t i = 0; i < q; ++i) {
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    long long res = 0;
    res += horizontal_lines[get_pos(x+w-1, y+h)];
    res -= horizontal_lines[get_pos(x-1, y+h)];
    res -= horizontal_lines[get_pos(x+w-1, y-1)];
    res += horizontal_lines[get_pos(x-1, y-1)];

    res += vertical_lines[get_pos(x+w, y+h-1)];
    res -= vertical_lines[get_pos(x-1, y+h-1)];
    res -= vertical_lines[get_pos(x+w, y-1)];
    res += vertical_lines[get_pos(x-1, y-1)];

    std::cout << res << std::endl;
  }

  return 0;
}
