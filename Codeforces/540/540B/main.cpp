#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n, k, p, x, y;
    scanf("%d %d %d %d %d", &n, &k, &p, &x, &y);

    std::vector<int> numbers;
    for(int i = 0; i < k; ++i) {
        int tmp;
        scanf("%d", &tmp);
        numbers.push_back(tmp);
    }

    int c = 0;
    for(auto i : numbers)
        if(i >= y)
            c++;

    while(c < (n+1)/2) {
        ++c;
        numbers.push_back(y);
    }

    if(numbers.size() > n) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    while(numbers.size() < n) {
        numbers.push_back(1);
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    if(sum > x) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    for(int i = k; i < n; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}
