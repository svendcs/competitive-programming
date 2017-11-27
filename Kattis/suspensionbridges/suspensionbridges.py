from math import *
def length(a, d):
    return 2 * a * sinh(d/(2*a))

d, s = map(int, input().split())

# a + s = a * cosh(d/(2*a))
begin = 0
end = 1000000000

for _ in range(500000):
    mid = (begin+end)/2
    if mid * cosh(d/(2*mid)) - mid  <= s:
        end = mid
    else:
        begin = mid

a = (begin+end)/2
print(length(a, d))
