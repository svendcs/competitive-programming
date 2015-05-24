#include <iostream>
#include <stdio.h>
#include <vector>

struct lucky_number {
    std::vector<char> digits;

    lucky_number() {
        digits.push_back(4);    
    }

    void increment() {
        for(int i = 0; i < digits.size(); ++i) {
            if(digits[i] == 4) {
                digits[i] = 7;
                return;
            }
            digits[i] = 4;
        }

        digits.push_back(4);
    }

    int representation() {
        int res = 0;
        for(int i = digits.size() - 1; i >= 0; --i)
            res = res * 10 + digits[i];
        return res;
    }
};

int main() {
    lucky_number a;
    int n; scanf("%d", &n);
    int i = 1;
    while(a.representation() != n) {
        ++i;
        a.increment();
    }

    printf("%d\n", i);

    return 0;
}
