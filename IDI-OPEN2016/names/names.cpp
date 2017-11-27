#include <iostream>
#include <algorithm>
#include <utility>
#include <limits>

const int INFTY = std::numeric_limits<int>::max()/2;
std::string name;

int mem[101][101];
int solve(int i, int j) {
    if (j-i < 1)
        return 0;
    int & res = mem[i][j];
    // std::cout << i << " " << j << " " << res << std::endl;
    if (res == INFTY) {
        res = std::min(res, 1+solve(i+1,j-1));
        if (j == name.size() - 1)
            res = std::min(res, 1+solve(i+1,j));
        if (name[i] == name[j])
            res = std::min(res, solve(i+1,j-1));
    }
    return res;

}

int main() {
    std::cin >> name;

    for (int i = 0; i < 100; ++i) for (int j = 0; j < 100; ++j) mem[i][j] = INFTY;
    std::cout << solve(0, name.size()-1) << std::endl;
    return 0;
}
