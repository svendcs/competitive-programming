#include <iostream>
#include <vector>
#include <limits>

struct quasinumber {
    bool repr[7];
    int size;

    quasinumber() {
        size = 1;
        repr[0] = true;
    }

    void increment() {
        int i = 0;
        for(i = 0; i <= size; ++i) {
            if(!repr[i]) {
                repr[i] = true;
                return;
            }
            else {
                repr[i] = false;
            }
        }

        if(i > size)
            ++size;
    }

    int representation() {
        int res = 0;
        for(int i = size - 1; i >= 0; --i) {
            res *= 10;
            res += (repr[i] ? 1 : 0);
        }

        return res;
    }
};

int main() {
    size_t n; std::cin >> n;

    std::vector<int> numbers;
    quasinumber a;
    do {
        numbers.push_back(a.representation());
        a.increment();
    } while(a.representation() <= n);

    int needed[n+1];
    int from[n+1];
    std::fill(needed, needed + n + 1, std::numeric_limits<int>::max());
    needed[0] = 0;
    for(auto q : numbers) {
        for(int i = 0; i <= n - q; ++i) {
            if(needed[i] + 1 < needed[i+q]) {
                from[i+q] = i;
                needed[i+q] = needed[i] + 1;
            }
        }
    }

    std::cout << needed[n] << std::endl;
    int i = n;
    while(i != 0) {
        std::cout << i - from[i] << " ";
        i = from[i];
    }
    std::cout << std::endl;

    return 0;
}
