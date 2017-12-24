# Input a, b
# (a * x) + 1 = b * y
# => x*b + (-y)*a  = 1

from __future__ import division, print_function
range = xrange
input = raw_input
from itertools import izip as zip, imap as map, ifilter as filter

import math 

def gcd(a, b):
    return gcd(b, a % b) if b != 0 else a

def euclid(a, b):
    if b != 0:
        d, y, x = euclid(b, a % b)
        y -= a//b*x
        return d, x, y
    return a, 1, 0

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())

    # print(a,b)

    d, x, y = euclid(b,a)
    if d != 1:
        print("IMPOSSIBLE")
    else:
        k = 1
        while x <= 0 or y >= 0:
            x += k * a
            y -= k * b
            k *= 2
        print(x)
