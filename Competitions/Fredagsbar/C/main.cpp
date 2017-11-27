#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <iomanip>

size_t to_index(size_t dd, size_t mm) {
    size_t r = (mm - 1) * 30;
    r += dd - 1;
    return r;
}

int main() {
    size_t n;
    std::cin >> n;
    size_t days[12*30];
    for(size_t i = 0; i < 12*30; ++i)
        days[i] = 0;
    for(size_t i = 0; i < n; ++i) {
        std::string day;
        std::cin >> day;
        size_t dd = (day[0] - '0') * 10+ (day[1] - '0');
        size_t mm = (day[2] - '0') * 10+ (day[3] - '0');
        // std::cout << to_index(dd, mm)<< std::endl;
        days[to_index(dd, mm)]++;
    }

    size_t current_count = 0;

    for(size_t i = 0; i < 30; ++i) {
        current_count += days[i];
    }
    size_t best_value = current_count;
    size_t best_index = 0;
    // std::cout << "blah";

    for(size_t i = 1; i < 30*12; ++i) {
        current_count -= days[i-1];
        current_count += days[(i+29) % (30*12)];
        if(current_count < best_value) {
            best_index = i;
            best_value = current_count;
        }
    }

    std::cout << std::setfill('0') << std::setw(2) << (best_index % 30) + 1 << std::setw(2) << (best_index/30)+1 << std::endl;

    return 0;

}
