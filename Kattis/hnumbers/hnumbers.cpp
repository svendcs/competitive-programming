#include <iostream>

const int MAX = 1000001;
int sieve[MAX+1];
int prefix[MAX+1];

int main() {
    std::fill(sieve, sieve+MAX+1, -1);

    for (int i=5; i*i<=MAX; i+= 4) {
        if (sieve[i] != -1) continue;

        for (int j=i*2; j <= MAX;  j += i)
            sieve[j] = i;
    }


    prefix[1] = 0;
    for (int i = 5; i <= MAX; i += 4) {
        // std::cout << i << " " << sieve[i] << " " << std::endl;
        bool is_semi_prime = (sieve[i] != -1 && sieve[i/sieve[i]] == -1 && sieve[sieve[i]] == -1 && sieve[i] != 1 && i/sieve[i] != 1);
        prefix[i] = prefix[i-4]+is_semi_prime;
    }

    int a; std::cin >> a;
    while (a != 0) {
        std::cout << a << " " << prefix[a] << std::endl;
        std::cin >> a;
    }

    return 0;
}
