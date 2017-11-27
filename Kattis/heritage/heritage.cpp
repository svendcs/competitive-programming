#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::string name;
    std::cin >> n >> name;

    std::vector<std::pair<std::string, long long>> dict(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> dict[i].first >> dict[i].second; 
    }

    long long meanings[100] = {0};
    for (size_t i = 0; i < name.size(); ++i) {
        for (size_t j = 0; j < n; ++j) {
            int k = i-dict[j].first.size()+1;
            if (k < 0) continue;
            if (name.substr(k,dict[j].first.size()) != dict[j].first) continue;

            // std::cout << "At position " << i << ", " << dict[j].first << std::endl;
            
            meanings[i] += (k == 0 ? 1 : meanings[k-1]) * dict[j].second;
            meanings[i] %= 1000000007;
        }
    }

    std::cout << meanings[name.size()-1] << std::endl;
    
    return 0;
}
