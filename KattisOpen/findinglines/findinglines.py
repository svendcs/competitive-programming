import random

n = int(input())
p = int(input())
p = n * p / 100

points = []
def cross(a,b):
    return a[0]*b[1] - a[1]*b[0]

def sub(a,b):
    return (a[0]-b[0], a[1]-b[1])

for _ in range(n):
    points.append(tuple(map(int, input().split())))

best = 0
for _ in range(100):
    a = points[random.randrange(n)]
    b = a
    while b == a:
        b = points[random.randrange(n)]

    c = 0
    for q in points:
        if cross(sub(b,a),sub(q,a)) == 0:
            c = c+1

    best = max(best,c)

if best < p:
    print("impossible")
else:
    print("possible")
