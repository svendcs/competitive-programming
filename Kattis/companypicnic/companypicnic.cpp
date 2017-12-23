#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

#define clamp(x, lo, hi) std::min(hi, std::max(lo, x))
#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct Person {
    double speed;
    std::vector<int> sub;
};

struct Res {
    int c;
    double speed;

    Res operator+=(const Res & other) {
        c += other.c;
        speed += other.speed;
        return *this;    
    }

    Res operator-=(const Res & other) {
        c -= other.c;
        speed -= other.speed;
        return *this;    
    }

    bool operator<(const Res & other) const {
        if (c != other.c)
            return c < other.c;
        return speed < other.speed;
    }
};


int n;
std::vector<Person> people(1000);
std::unordered_map<std::string, int> names;
std::vector<bool> mem_set(1000);
std::vector<Res> mem(1000);
int ceo = 0;

Res best(int i) {
    if (mem_set[i])
        return mem[i];
    mem_set[i] = true;

    // Construct the solution where this person is not used
    Res a = {0,0};
    for (auto c : people[i].sub)
        a += best(c);
    Res res = a;

    // Construct solution where each subordinate is paired
    for (auto c : people[i].sub) {
        // reuse previous calculation
        Res b = a;
        b -= best(c);
        for (auto d : people[c].sub) {
            b += best(d);
        }
        b += {1, std::min(people[i].speed, people[c].speed)};

        res = std::max(res, b);
    }

    return mem[i] = res;
}

int main() {
    std::cin >> n;
    std::fill(mem_set.begin(), mem_set.end(), false);

    // first read the input to generate map of names
    std::vector<std::tuple<std::string, double, std::string>> input(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> std::get<0>(input[i]) >> std::get<1>(input[i]) >> std::get<2>(input[i]);
        names[std::get<0>(input[i])] = i;
    }

    // build the tree
    for (size_t i = 0; i < n; ++i) {
        people[i].speed = std::get<1>(input[i]);

        if(std::get<2>(input[i]) == "CEO")
            ceo = i;
        else
            people[names[std::get<2>(input[i])]].sub.push_back(i);

    }

    auto res = best(ceo);
    std::cout << res.c << " " << res.speed / res.c << std::endl;
    return 0;
}
