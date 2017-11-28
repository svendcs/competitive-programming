#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

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

typedef Point<int> P;

template <typename T>
std::ostream & operator<<(std::ostream & out, const Point<T> & p) {
    return out << "(" << p.x << "; " << p.y << ")";
}

template <typename T>
std::istream & operator>>(std::istream & in, Point<T> & p) {
    return in >> p.x >> p.y;
}

int main() {
    int h, w;
    int cas = 0;
    while (std::cin >> h >> w) {
        ++cas;
        char input[h][w+1];
        for (size_t i = 0; i < h; ++i)
            std::cin >> input[i];

        bool visited[h][w];
        for (size_t i = 0; i < h; ++i) for (size_t j = 0; j < w; ++j)
            visited[i][j] = false;

        size_t res = 0;
        for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
            if (input[i][j] != '-') continue;
            if (visited[i][j]) continue;

            std::queue<P> queue;
            queue.push({j,i});

            ++res;
            while (!queue.empty()) {
                P e = queue.front(); queue.pop();

                if (e.x + 1 < w && input[e.y][e.x+1] == '-' && !visited[e.y][e.x+1]) {
                    visited[e.y][e.x+1] = true;
                    queue.push({e.x+1, e.y});
                }

                if (e.x - 1 >= 0 && input[e.y][e.x-1] == '-' && !visited[e.y][e.x-1]) {
                    visited[e.y][e.x-1] = true;
                    queue.push({e.x-1, e.y});
                }

                if (e.y + 1 < h && input[e.y+1][e.x] == '-' && !visited[e.y+1][e.x]) {
                    visited[e.y+1][e.x] = true;
                    queue.push({e.x, e.y+1});
                }

                if (e.y - 1 >= 0 && input[e.y-1][e.x] == '-' && !visited[e.y-1][e.x]) {
                    visited[e.y-1][e.x] = true;
                    queue.push({e.x, e.y-1});
                }
            }
        }

        std::cout << "Case " << cas << ": " << res << std::endl;
        
    }
    return 0;
}
