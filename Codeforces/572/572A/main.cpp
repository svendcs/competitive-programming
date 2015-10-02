#include <iostream>
#include <vector>

int main() {
    int na, nb, k, m;
    std::cin >> na >> nb >> k >> m;

    std::vector<int> a, b;
    
    int tmp;
    for(int i = 0; i < na; ++i) {
        std::cin >> tmp;
        a.push_back(tmp);
    }

    for(int i = 0; i < nb; ++i) {
        std::cin >> tmp;
        b.push_back(tmp);
    }

    if(a[k-1] < b[nb-m])
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    return 0;
}
