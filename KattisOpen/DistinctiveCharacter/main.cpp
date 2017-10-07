#include <iostream>
#include <queue>
#include <cmath>

int to_number(const std::string k) {
    int res = 0;
    for(char c : k) {
        res = res * 2 + c - '0';
    }

    return res;
}

char switch_char(char c) {
    if (c=='0')
        return '1';
    return '0';
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<std::pair<int, std::string>> queue;
    bool visited[1058576] = {false}; // 2^20 + a bit extra
    for(int i = 0; i < n; ++i) {
        std::string t;
        std::cin >> t;
        queue.push({0, t});
        visited[to_number(t)] = true;
    }
    
    int max = 0;
    std::string res;
    while(!queue.empty()) {
        auto e = queue.front();
        queue.pop();

        if (e.first >= max) {
            max = e.first;
            res = e.second;
        }
        std::string s = e.second;
        for(int i = 0; i < k; ++i) {
            s[i] = switch_char(s[i]);
            if (!visited[to_number(s)]) {
                visited[to_number(s)] = true;
                queue.push({e.first+1, s});
            }
            s[i] = switch_char(s[i]);
        }
    }

    std::cout << res << std::endl;
}
