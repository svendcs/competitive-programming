#include <iostream>

long long required(long long n, long long k) {
    long long res = 0;
    for(long long i = 1; i <= n; ++i) {
        res += i * k; 
    }
    return res;
}

int main() {
    long long k, n, w; // k dollars, has n dollars, w bananas
    std::cin >> k >> n >> w;

    long long r = required(w, k);
    if(r <= n)
        std::cout << 0 << std::endl;
    else
        std::cout << r - n << std::endl;
    return 0;
}
