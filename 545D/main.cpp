#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    size_t n; 
    std::cin >> n; 
    std::vector<unsigned long long> times;
    for(size_t i = 0; i < n; ++i) {
        unsigned long long tmp; std::cin >> tmp;
        times.push_back(tmp);
    }

    std::sort(times.begin(), times.end());

    unsigned long long total_time = 0;
    size_t result = 0;
    for(size_t i = 0; i < n; ++i) {
        if(times[i] >= total_time) { // don't times of people who are not served
            result++;
            total_time += times[i];
        } 
    }

    std::cout << result << std::endl;
    return 0;
}
