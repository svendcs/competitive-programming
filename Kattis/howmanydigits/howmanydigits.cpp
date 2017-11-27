#include <iostream>
#include <cmath>

int main() {
    double sums[1000001];
    sums[1] = 0;

    for(size_t i = 2; i <= 1000000; ++i)
        sums[i] = sums[i-1] + log10(i);
    sums[0] = sums[1] = 1;

    size_t n;
    while(std::cin >> n)
        std::cout << static_cast<size_t>(ceil(sums[n])) << std::endl;
}
