#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <set>

typedef long long ll;

struct Point {
    ll x, y;
};

struct Line {
    // ax + by + c == 0
    ll a, b, c;
};

bool parallel(const Line &a, const Line &b) {
    if (a.b == 0 || b.b == 0) // vertical case
        return a.b == 0 && b.b == 0;

    return b.a*a.b == a.a*b.b; // check if slopes equal
}

bool sideness(const Line &l, const Point &p) {
    if (l.b == 0) // vertical case
        return -l.c > p.x*l.a;

    return -(l.a * p.x + l.c) > p.y * l.b;
}

int main() {
    int cases; std::cin >> cases;
    for(size_t c = 0; c < cases; ++c) {
        int n, m;
        std::cin >> n >> m;
        std::vector<Line> lines(n);

        int faces = 1 + n; // number of faces is 1 + n + #intersections
        for(size_t i = 0; i < n; ++i) {
            Line & l = lines[i];
            std::cin >> l.a >> l.b >> l.c;

            for(size_t j = 0; j < i; ++j) {
                if (!parallel(l, lines[j]))
                    ++faces;
            }
        }

        std::set<std::pair<long, long>> occupied_faces;
        for(size_t i = 0; i < m; ++i) {
            Point knight;
            std::cin >> knight.x >> knight.y;

            // std::cerr << "New knight" << std::endl;
            std::pair<long,long> sidedness = {0,0};
            for(size_t j = 0; j < n; ++j) {
                long & a = (j < 50 ? sidedness.first : sidedness.second);
                a += sideness(lines[j], knight);
                a *= 2;
            }

            occupied_faces.insert(sidedness);
        }

        // std::cerr << faces << " " << occupied_faces.size() << std::endl;
        std::cout << (faces == occupied_faces.size() ? "PROTECTED" : "VULNERABLE") << std::endl;
    }
}
