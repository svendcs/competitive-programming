#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

struct AgencyInfo {
    std::string name;
    int a, b;
};
AgencyInfo parse_agency(std::string line) {
    AgencyInfo res;
    size_t i = 0;
    {
        std::stringstream a;
        for(; line[i] != ':'; ++i) {
            a << line[i];
        }
        res.name = a.str();
    }

    ++i;

    res.a = 0;
    for(; line[i] != ','; ++i) {
        res.a = res.a * 10 + (line[i] - '0');
    }

    ++i;
    res.b = 0;
    for(; i < line.size(); ++i) {
        res.b = res.b * 10 + (line[i] - '0');
    }

    return res;
}

struct Agency {
    std::string name;
    int price;

    bool operator<(const Agency & other) const {
        if (price != other.price)
            return price < other.price;
        return name < other.name;
    }
};

int main() {
    size_t cases; std::cin >> cases;
    for (size_t cas = 1; cas <= cases; ++cas) {
        int start, target, n;
        std::cin >> start >> target >> n;

        std::vector<Agency> agencies;
        for (size_t i = 0; i < n; ++i) {
            std::string line;
            std::cin >> line;
            auto info = parse_agency(line);

            int cur = start;
            int price = 0;
            while (cur / 2 >= target && ((cur - cur/2) * info.a > info.b)) {
                cur /= 2;
                price += info.b;
            }

            while (cur > target) {
                price += info.a;
                --cur;
            }
            agencies.push_back({info.name, price});
        }

        std::sort(agencies.begin(), agencies.end());
        std::cout << "Case " << cas << std::endl;
        for (auto a : agencies) {
            std::cout << a.name << " " << a.price << std::endl;
        }
    }
    return 0;
}
