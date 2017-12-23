from __future__ import division, print_function
range = xrange
input = raw_input
from itertools import izip as zip, imap as map, ifilter as filter

import math 

# sum_{i=1}^{h} 3h-1

# print(3 * ((h+1)*h/2) - h)

h = int(input())
c = 3 * ((h+1)*h//2) - h

while c % 4 != 0:
    h += 1
    c += 3*h-1

print(h)

