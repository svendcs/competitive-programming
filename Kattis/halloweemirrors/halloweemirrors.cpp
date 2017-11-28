#include <algorithm>
#include <utility>
#include <iostream>
#include <cmath>
#include <vector>

#define clamp(x, lo, hi) std::min(hi, std::max(lo, x))

template <typename T>
struct Point {
    T x, y;

    Point operator+(const Point & other) const {
        return {x+other.x, y+other.y};
    }

    Point operator-(const Point & other) const {
        return {x-other.x, y-other.y};
    }

    Point operator*(const T & k) const {
        return {x * k, y * k};
    }

    T length_squared() const {
        return x*x + y*y;
    }

    double length() const {
        return sqrt(length_squared());
    }

    T cross(const Point & other) const {
        return x*other.y - y*other.x;
    }

    T dot(const Point & other) const {
        return x*other.x + y*other.y;
    }

    double angle(const Point & other) const {
        double a = (dot(other) / length()) / other.length();
        return acos(clamp(a, -1.0, 1.0));
    }
};

template <typename T>
std::ostream & operator<<(std::ostream & out, const Point<T> & p) {
    return out << "(" << p.x << "; " << p.y << ")";
}

template <typename T>
std::istream & operator>>(std::istream & in, Point<T> & p) {
    return in >> p.x >> p.y;
}

typedef Point<int> P;

int main() {
    int n = 0; std::cin >> n;

    while (n != 0) {
        std::vector<std::pair<P, P>> mirrors(n);
        for (size_t i = 0; i < n; ++i) {
            std::cin >> mirrors[i].first >> mirrors[i].second;
        }

        int m; std::cin >> m; 
        for (size_t i = 0; i < m; ++i) {
            P loc; std::cin >> loc;
            size_t count = 0;
            for (auto mirror : mirrors) {
                auto a = mirror.second - mirror.first;
                auto b = loc - mirror.first;

                auto c = mirror.first - mirror.second;
                auto d = loc - mirror.second;

                // std::cerr << loc << " " << mirror.first << " " << mirror.second << std::endl;
                // std::cerr << a.angle(b) * 180/M_PI << " " << c.angle(d) * 180/M_PI << std::endl;
                if (a.angle(b) <= M_PI/2 && c.angle(d) <= M_PI/2) ++count;
            }

            std::cout << count << std::endl;
        }

        std::cout << std::endl;
        std::cin >> n;
    }
    return 0;
}
