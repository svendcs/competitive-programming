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

class Line:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        return "({} - {})".format(self.a, self.b)

    def signed_dist_point(self, p):
        return (self.a - self.b).cross(p - self.a) / (self.b - self.a).length()

    def dist_point(self, p):
        return abs(self.signed_dist_point(p))


n = int(input())
for _ in range(n):
    coords = list(map(int, input().split()))
    p1 = Point(*coords[0:2])
    p2 = Point(*coords[2:4])
    horricane = Line(p1, p2)

    dval = []
    dmin = float("inf")

    m = int(input())
    for _ in range(m):
        a = input().split()
        name = a[0]
        city = Point(int(a[1]), int(a[2]))
        dist = horricane.dist_point(city) 

        if abs(dist - dmin) < 10E-6:
            dval.append(name)
        elif dist < dmin:
            dmin = dist
            dval = [name]

    print(*dval)

