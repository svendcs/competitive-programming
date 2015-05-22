#include <iostream>
#include <bitset>
#include <stdio.h>

#ifdef LOCAL
    const int MAX = 50000; // OSX does not like very big arrays.
#else
    const int MAX = 5000000;
#endif

int main() {
    // this solution gets timelimit exceeded, but the idea is the same.
    // find prime numbers using sieve of erathothenes
    int factors[MAX+1] = {};

    for(int i = 2; i*i <= MAX; ++i) {
        if(factors[i] != 0) continue;

        for(int j = i*i; j <= MAX; j += i)
            factors[j] = i;
    }

    // compute number of factors
    for(int i = 1; i <= MAX; ++i) {
        if(factors[i] == 0)
            factors[i] = 1;
        else
            factors[i] = factors[i/factors[i]]+1;
    }

    // compute prefix sum
    for(int i = 2; i <= MAX; ++i)
        factors[i] += factors[i-1];


    int t; scanf("%d", &t);
    for(int i = 0; i < t; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        std::cout << factors[a] - factors[b] << std::endl;
    }
    return 0;
}
