#include <iostream>

int main() {
    int n; std::cin >> n;
    int badges[n];
    for(int i = 0; i < n; ++i) std::cin >> badges[i];

    bool taken[n*3]; std::fill(taken, taken + sizeof(taken), false);

    int coins = 0;
    for(int i = 0; i < n; ++i) {
        while(taken[badges[i]]) {
            ++badges[i];
            ++coins;
        }

        taken[badges[i]] = true;
    }

    std::cout << coins << std::endl;
}
