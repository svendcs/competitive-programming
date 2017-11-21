#include <cmath>
#include <random>
#include <iostream>

struct Point {
    long long x, y;
};

Point operator-(const Point & a, const Point & b) {
    return {a.x - b.x, a.y - b.y};
}

bool colinear(const Point & a, const Point & b, const Point & c) {
    return ((b.x - a.x) * (c.y - a.y) == (c.x-a.x) * (b.y - a.y));

}

int main() {
    int n; std::cin >> n;

    int p;
    std::cin >> p;
    p = std::ceil(n * p / 100.0);

    std::default_random_engine eng;
    std::uniform_int_distribution<int> distribution(0,n-1);

    std::vector<Point> points;

    for(size_t i = 0; i < n; ++i) {
       Point p;
       std::cin >> p.x >> p.y;
       points.push_back(p);
    }

    if (n == 1) {
        std::cout << "possible" << std::endl;
        return 0;
    }

    for(size_t r = 0; r < 1000; ++r) {
        int a = distribution(eng);
        int b = distribution(eng);

        if(a == b) continue;

        size_t c = 0;
        for(size_t i = 0; i < n; ++i) {
            if(!colinear(points[a], points[b], points[i])) continue;
            ++c;
        }

        if (c >= p) {
            std::cout << "possible" << std::endl;
            return 0;
        }
    }

    std::cout << "impossible" << std::endl;
    return 0;
}
