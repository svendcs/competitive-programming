from __future__ import division, print_function
range = xrange
input = raw_input
from itertools import izip as zip, imap as map, ifilter as filter
import sys

import math 

mem = {}
def combine(a, b, op):
    res = set();
    for x in a:
        for y in b:
            if op == '*':
                res.add(x*y)
            elif op == '+':
                res.add(x+y)
            elif op == '-':
                res.add(x-y)

    return res;

def solutions(eq):
    if len(eq) is 1:
        return set([int(eq[0])])
    if " ".join(eq) in mem:
        return mem[" ".join(eq)]

    res = set()
    for i in range(1, len(eq), 2):
        a = combine(solutions(eq[:i]), solutions(eq[i+1:]), eq[i])
        res |= a

    mem[" ".join(eq)] = res
    return res

for line in sys.stdin:
    mem = {}
    eq = line.split()
    if not eq:
        break
    for x in sorted(solutions(eq)):
        print(x)
    print()
