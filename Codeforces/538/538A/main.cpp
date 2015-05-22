#include <iostream>

bool possible(std::string banner) {
    std::string codeforces = "CODEFORCES";
    // we can either cut from left, right or in the middle
    if(banner.size() < codeforces.size())
        return false;
    if(banner.substr(0, codeforces.size()) == codeforces) // from the left
        return true;
    if(banner.substr(banner.size() - codeforces.size(), codeforces.size()) == codeforces) // from the right
        return true;

    // in the middle
    int j = 0;
    for(int i = 0; i < banner.size() && banner[i] == codeforces[j]; ++i, ++j);
    int len = codeforces.size() - j;
    return banner.substr(banner.size() - len, len) == codeforces.substr(j);
}

int main() {
    std::string banner; std::cin >> banner;
    std::cout << (possible(banner) ? "YES" : "NO") << std::endl;

    return 0;
}
