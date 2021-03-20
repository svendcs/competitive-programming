#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
  long long n;
  std::cin >> n;


  long double begin = 1;
  long double end = n;

  for (size_t i = 0; i < 10000; ++i) {
    long double mid = (begin + end)/2;
    long double num = std::pow(mid, mid);

    // std::cout << mid << " " << num << std::endl;

    if (num > n)
      end = mid;
    else
      begin = mid;
  }

  std::cout << std::setprecision(20) << (begin+end)/2 << std::endl;
}
