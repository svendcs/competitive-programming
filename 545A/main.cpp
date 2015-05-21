#include <iostream>
#include <vector>

int main() {
    int matrix[100][100];
    int n; std::cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> matrix[j][i];
        }
    }

    std::vector<int> result;
    for(int i = 0; i < n; ++i) {
        bool bad = false;
        for(int j = 0; j < n; ++j) {
            if(matrix[j][i] == 1 || matrix[j][i] == 3)
                bad = true;
        }

        if(bad) continue;

        result.push_back(i+1);
    }

    std::cout << result.size() << std::endl;
    for(auto i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
