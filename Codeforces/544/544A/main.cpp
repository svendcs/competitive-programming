#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int k; std::cin >> k;
    std::string q; std::cin >> q;

    bool characters[26];
    std::fill(characters, characters + 26, false);

    size_t distinct_chars = 0;
    for(char c : q) {
        size_t i = c - 'a';
        if(!characters[i]) {
            characters[i] = true;
            ++distinct_chars;
        }
    }

    if(distinct_chars < k) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    std::cout << "YES" << std::endl;
    size_t begin = 0;
    characters[q[0]-'a'] = false;
    --k;
    for(size_t i = 1; i < q.size() && k > 0; ++i) {
        if(characters[q[i]-'a']) {
            characters[q[i]-'a'] = false;
            std::cout << q.substr(begin, i-begin) << std::endl;
            begin = i;
            --k;
        }
    }

    std::cout << q.substr(begin) << std::endl;
}
