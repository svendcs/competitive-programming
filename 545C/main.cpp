#include <iostream>
#include <algorithm>
#include <limits>

const int max_n = 100001;

int main() {
    std::pair<long long, long long> trees[max_n];
    int n; std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::cin >> trees[i].first >> trees[i].second;
    }
    trees[n].first = std::numeric_limits<long long>::max();

    long long x = std::numeric_limits<long long>::min();
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(trees[i].first - trees[i].second > x) {
            ++count;
            x = trees[i].first;
        }
        else if(trees[i].first + trees[i].second < trees[i+1].first) {
            ++count;
            x = trees[i].first + trees[i].second;
        }
        else
            x = trees[i].first;
    }

    std::cout << count << std::endl;

    return 0;
}
