#include <iostream>

int lcp(std::string a, std::string b) {
    int i = 0;
    for(; i < a.size() && i < b.size() && a[i] == b[i]; ++i);
    return i;
}

int lcs(std::string a, std::string b) {
    int i = 0;
    for(; i < a.size() && i < b.size() && a[a.size() - 1 - i] == b[b.size() - 1 - i]; ++i);
    return i;
}

bool possible(std::string banner) {
    std::string codeforces = "CODEFORCES";

    int a = lcp(banner, codeforces);
    int b = lcs(banner, codeforces);

    return a + b >= codeforces.size();
}

int main() {
    std::string banner; std::cin >> banner;
    std::cout << (possible(banner) ? "YES" : "NO") << std::endl;

    return 0;
}
