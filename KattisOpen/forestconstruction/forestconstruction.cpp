#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

int main() {
    int v; std::cin >> v;
    std::vector<std::pair<int, int>> internal;
    std::vector<int> leaves;
    std::vector<std::pair<int, int>> edges;
    for(size_t i = 0; i < v; ++i) {
        int t; std::cin >> t;
        if (t == 1)
            leaves.push_back(i);
        else if (t >= 2)
            internal.push_back({i, t});
    }

    for(size_t i = 0; i < internal.size(); ++i) {
        if (i < internal.size() - 1) {
            edges.push_back({internal[i].first, internal[i+1].first});
            internal[i].second--;
            internal[i+1].second--;
        }

        while (internal[i].second > 0) {
            if (leaves.empty()) {
                std::cout << "IMPOSSIBLE" << std::endl;
                return 0;
            }

            edges.push_back({internal[i].first, leaves.back()});
            leaves.pop_back();
            internal[i].second--;
        }
    }

    if (leaves.size() % 2 != 0) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    for (size_t i = 0; i < leaves.size(); i += 2) {
        edges.push_back({leaves[i], leaves[i+1]});
        
    }

    std::sort(edges.begin(), edges.end());
    std::cout << "POSSIBLE" << std::endl;
    for(auto edge : edges) {
        std::cout << edge.first+1 << " " << edge.second+1 << std::endl;
    }

    return 0;
}
