#include <set>
#include <iostream>

int main() {
    std::string input;
    std::cin >> input;
    int n = input.size();

    std::set<int> zeroes;
    zeroes.insert(-1);
    zeroes.insert(n);
    for (size_t i = 0; i < n; ++i) {
        if (input[i] == '0')
            zeroes.insert(i);
    }

    // for (int pos : zeroes)
    //     std::cerr << pos << " ";
    // std::cerr << std::endl;

    for (size_t i = 0; i < n; ++i) {
        if (input[i] != '2') continue;
        // std::cerr << *l << " " << i << " " << *r << std::endl;
        //
        auto r = zeroes.lower_bound(i);
        auto l = std::prev(r);

        int p = *l + *r - i;
        if (*l != -1) // do not erase sentinels
            zeroes.erase(l);
        if (*r != n) // do not erase sentinels
            zeroes.erase(r);
        zeroes.insert(p);
    }

    std::string res;
    auto j = std::next(zeroes.begin());
    for (size_t i = 0; i < n; ++i) {
        if (i > *j) ++j;
        res += (i == *j ? '0' : '1');
    }

    std::cout << res << std::endl;
}
