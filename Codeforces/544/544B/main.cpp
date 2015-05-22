#include <iostream>
#include <algorithm>

int main() {
    int n, k; std::cin >> n >> k;
    char map[n][n]; // y, x

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        map[i][j] = 'S';
    }

    for(int i = 0; i < n; i++) {
        for(int j = i%2; j < n; j += 2) {
            if(k == 0) break;
            
            map[i][j] = 'L';
            --k;
        }
    }

    if(k != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }

}
