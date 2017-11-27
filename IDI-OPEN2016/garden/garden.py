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

    def dist_squared(self):
        return self.x**2 + self.y**2

    def dist(self):
        return math.sqrt(self.dist_squared())

    def cross(self, other):
        return self.x*other.y - self.y*other.x;

class Line:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        return "({} - {})".format(self.a, self.b)

    def signed_dist_point(self, p):
        return (self.a - self.b).cross(p - self.a) / (self.b - self.a).dist()

    def dist_point(self, p):
        return abs(self.signed_dist_point(p))

class Circle:
    def __init__(self, r):
        self.r = r

    def area(self):
        return math.pi * self.r**2

    # area of circle sector with angle phi
    def sector_area(self, phi):
        return self.r**2 * phi / 2

    # area of segment(triangle) with angle phi
    def segment_area(self, phi):
        return (self.r**2 / 2) * (phi - math.sin(phi))

def area(r, t):
    c = Circle(r)
    if r <= t: # circle does not touch line
        return c.area()
    elif t == 0: # the circle is cut in half
        return c.area() / 2
    else:
        phi = 2*math.acos(t/r)
        return c.area() - (c.sector_area(phi) + c.segment_area(phi))

a = int(input())

p1 = Point(*map(int, input().split()))
p2 = Point(*map(int, input().split()))
orig = Point(0,0)
t = Line(p1, p2).dist_point(orig)

low = 0
high = 10000

for i in range(1000):
    mid = (low+high)/2

    if area(mid, t) > a:
        high = mid
    else:
        low = mid

print(math.ceil((low+high)/2))
