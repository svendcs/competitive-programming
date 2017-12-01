#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <unordered_set>

#define clamp(x, lo, hi) std::min(hi, std::max(lo, x))
#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct Entry {
    int a, b, c;
    size_t id;
};

std::ostream & operator<<(std::ostream & o, const Entry & a) {
    return o << "(id=" << a.id << ", a=" << a.a << ", b=" << a.b << ", c=" << a.c << ")";
}

int main() {
    int t; std::cin >> t;
    rep(cas, 0, t) {
        // std::cout << "Case " << cas+1 << std::endl;
        int n; std::cin >> n;
        std::vector<Entry> people_a(n), people_b(n), people_c(n);
        rep(i,0,n) {
            people_a[i].id = i;
            std::cin >> people_a[i].a;
            std::cin >> people_a[i].b;
            std::cin >> people_a[i].c;
        }
        std::copy(people_a.begin(), people_a.end(), people_b.begin());
        std::copy(people_a.begin(), people_a.end(), people_c.begin());

        std::sort(people_a.begin(), people_a.end(), [](const Entry & a, const Entry & b) {
            return a.a < b.a;         
        });
        std::sort(people_b.begin(), people_b.end(), [](const Entry & a, const Entry & b) {
            return a.b < b.b;         
        });
        std::sort(people_c.begin(), people_c.end(), [](const Entry & a, const Entry & b) {
            return a.c < b.c;         
        });

        int best = -1;
        rep(i, 0, n) {
            int a = people_a[i].a;
            std::unordered_set<int> current;

            int k = n-1;
            rep(j, 0, n) {
                int b = people_b[j].b;
                int c = 10000 - a - b;

                if (c < 0) break;

                // std::cout << a << " " << b << " " << c << std::endl;
                while (k >= 0 && people_c[k].c > c) {
                    // std::cout << "Erasing " << people_c[k] << std::endl;
                    current.erase(people_c[k--].id);
                }


                if (k == -1) break;

                // std::cout << "Testing " << people_b[j] << std::endl;
                if (people_b[j].a <= a && people_b[j].b <= b && people_b[j].c <= c) {
                    // std::cout << "Inserting" << std::endl;
                    current.insert(people_b[j].id);
                }

                best = std::max(best, (int) current.size());
            }
        }

        std::cout << "Case #" << cas + 1<< ": " << best << std::endl;
    }
}
