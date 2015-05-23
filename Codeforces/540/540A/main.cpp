#include <iostream>
#include <cmath>

int main() {
    int n; std::cin >> n;
    std::string a, b; std::cin >> a >> b;
    int dist = 0; 
    
    for(int i = 0; i < a.size(); ++i) {
        int diff = std::abs(a[i] - b[i]);
        dist += std::min(diff, 10-diff);
    }
    std::cout << dist << std::endl;
    return 0;
}   
