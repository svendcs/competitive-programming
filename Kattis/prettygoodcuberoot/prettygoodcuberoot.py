import sys
import math

def compare(a, b, n):
    d1 = abs(a**3 - n)
    d2 = abs(b**3 - n)
    return a if d1 < d2 else b

for line in sys.stdin:
    n = int(line)

    a = 1
    b = n
    while a < b:
        mid = (a+b)//2
        if mid ** 3 == n:
            break
        if mid ** 3 > n:
            b = mid-1
        else:
            a = mid+1
    r = (a + b) // 2
    r = compare(r, r+1, n)
    r = compare(r, r-1, n)
    print(r)
