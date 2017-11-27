#include <cmath>
#include <iostream>

long sum(long n)
{
    std::cout << "Call " << n << std::endl;
    if (n<=0)
        return 0;
    if (n<10)
      return n*(n+1)/2;
 
    long d = log10(n);
 
    long *a = new long[d+1];
    a[0] = 0, a[1] = 45;
    for (long i=2; i<=d; i++)
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));
 
    long p = ceil(pow(10, d));
 
    long msd = n/p;
 
    return msd*a[d] + (msd*(msd-1)/2)*p +  
           msd*(1+n%p) + sum(n%p);
}
 
int main()
{
    size_t testcases;
    std::cin >> testcases;

    for(size_t i = 0; i < testcases; ++i) {
        long a, b;
        std::cin >> a >> b;
        std::cout << sum(b) - sum(a-1) << std::endl;
    }
    return 0;
}
