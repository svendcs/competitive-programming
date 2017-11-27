import math

def digitsum(n):
    if n <= 0:
        return 0
    if (n < 10):
        return n * (n+1)//2
    d = int(math.log10(n))
    a = [0 for i in range(d+1)]
    a[0] = 0
    a[1] = 45
    for i in range(2, d+1):
        a[i] = a[i-1] * 10 + 45 * 10 ** (i-1)
    p = (10 ** d)
    msd = n // p

    return msd * a[d] + (msd * (msd-1)//2) * p + msd * (1+n%p) + digitsum(n%p)

for testcase in range(int(input())):
    a, b = map(int, input().split())
    print(digitsum(b) - digitsum(a-1))
