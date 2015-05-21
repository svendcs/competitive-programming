#include <iostream>
#include <string>

size_t distance(std::string a, std::string b) {
    size_t res = 0;
    for(size_t i = 0; i < a.size(); ++i) {
        if(a[i] != b[i])
            ++res;
    }

    return res;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    size_t d = distance(a, b);
    if(d % 2 != 0) {
        std::cout << "impossible" << std::endl;
        return 0;
    }

    std::string c;
    for(size_t i = 0; i < a.size(); ++i) {
        if(a[i] == b[i]) {
            c.push_back(a[i]);
            continue;
        }
        if(d % 2 == 0)
            c.push_back(a[i]);
        else
            c.push_back(b[i]);
        --d;
    }

    std::cout << c << std::endl;
}
