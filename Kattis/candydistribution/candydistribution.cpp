#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <tuple>

#define clamp(x, lo, hi) std::min(hi, std::max(lo, x))
#define rep(i, a, b) for(int i = a; i < (b); ++i)

template <typename T>
T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }

template <typename T>
T lcm(T a, T b) { return std::abs(a) / gcd(a, b) * std::abs(b); }

template <typename T>
std::tuple<T, T, T> euclid(T a, T b) {
    if (b != 0) {
        T d, x, y;
        std::tie(d, y, x) = euclid(b, a % b);
        y -= a / b * x;
        return std::make_tuple(d, x, y);
    }

    return std::make_tuple(a, 1, 0);
}

int main() {
    size_t t; std::cin >> t;
    rep(i, 0, t) {
        long a, b, d, x, y; std::cin >> a >> b;
        std::tie(d, x, y) = euclid(b, a);

        if (d != 1) {
            std::cout << "IMPOSSIBLE" << std::endl;
            continue;
        }

        long k = 1;
        while (x <= 0 || y >= 0) {
            x += k * a;
            y -= k * b;
            k *= 2;
        }

        std::cout << x << std::endl;
    }
    return 0;
}
