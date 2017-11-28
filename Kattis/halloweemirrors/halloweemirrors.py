from __future__ import division, print_function
range = xrange
input = raw_input
from itertools import izip as zip, imap as map, ifilter as filter

import math 

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return "({}; {})".format(self.x, self.y)

    def __add__(self, other):
        return Point(self.x+other.x, self.y+other.y)

    def __sub__(self, other):
        return Point(self.x-other.x, self.y-other.y)

    def __mul__(self, c):
        return Point(self.x*c, self.y*c)

    def length_squared(self):
        return self.x**2 + self.y**2

    def length(self):
        return math.sqrt(self.length_squared())

    def cross(self, other):
        return self.x*other.y - self.y*other.x

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    def angle(self, other):
        a = self.dot(other) / (self.length() * other.length())
        a = max(min(a, 1),-1)
        return math.acos(a)

n = int(input())

while n != 0:
    mirrors = []
    for _ in range(n):
        coords = list(map(int, input().split()))
        mirrors.append((Point(*coords[0:2]), Point(*coords[2:4])))

    m = int(input())
    for _ in range(m):
        loc = Point(*map(int, input().split()))
        count = 0
        for mirror in mirrors:
            a = mirror[1]-mirror[0]
            b = loc - mirror[0]

            c = mirror[0]-mirror[1]
            d = loc - mirror[1]

            if a.angle(b) <= math.pi/2 and c.angle(d) <= math.pi/2:
                count += 1
        print(count)
    print()


    n = int(input())
