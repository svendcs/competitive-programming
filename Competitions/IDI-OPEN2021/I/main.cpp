#include <iostream>

static constexpr size_t SIZE = 351;
int main() {
  int x, y;
  int bytes[SIZE][SIZE];

  std::cin >> y >> x;
  for (size_t i = 0; i < y; ++i) {
    for (size_t j = 0; j < x; ++j) {
      std::cin >> bytes[i][j];
    }
  }

  int sub_bytes[SIZE][SIZE];
  int up_bytes[SIZE][SIZE];
  int avg_bytes[SIZE][SIZE];

  for (size_t i = 0; i < y; ++i) {
    for (size_t j = 0; j < x; ++j) {
      const auto b = (i > 0 ? bytes[i-1][j] : 0);
      const auto a = (j > 0 ? bytes[i][j-1] : 0);
      const auto x = bytes[i][j];

      sub_bytes[i][j] = ((x - a) + 256) % 256;
      up_bytes[i][j] = ((x - b) + 256) % 256;
      avg_bytes[i][j] = ((x - ((a + b)% 256)/2) + 256) % 256;
    }
  }

  size_t max = 0;
  size_t arg_max = 0;
  for (int byte = 0; byte < 256; ++byte) {
    size_t freq = 0;
    for (size_t i = 0; i < y; ++i) {
      size_t sub_count = 0;
      size_t none_count = 0;
      size_t up_count = 0;
      size_t avg_count = 0;

      for (size_t j = 0; j < x; ++j) {
        if (sub_bytes[i][j] == byte)
          ++sub_count;
        if (bytes[i][j] == byte)
          ++none_count;
        if (avg_bytes[i][j] == byte)
          ++avg_count;
        if (up_bytes[i][j] == byte)
          ++up_count;
      }

      freq += std::max(sub_count, std::max(none_count, std::max(up_count, avg_count)));
    }

    // std::cout << freq << " " << byte << std::endl;
    if (freq >= max) {
      max = freq;
      arg_max = byte;
    }
  }

  std::cout << arg_max << " " << max << std::endl;

  return 0;
}

