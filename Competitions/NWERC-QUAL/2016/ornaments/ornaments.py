import math

while True:
    r, h, s = map(int, input().split())

    if r == 0:
        break
    
    b = math.sqrt(h*h-r*r)
    phi = math.pi/ 2 - math.atan(b/r)

    a = math.pi * r + b * 2 + 2*phi * r
    res = a * (100 + s)/100
    print("{:.2f}".format(res))
