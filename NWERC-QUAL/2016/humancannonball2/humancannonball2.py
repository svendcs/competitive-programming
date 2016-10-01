import math

n = int(input())

for testcase in range(n):
    v, phi, x1, h1, h2 = map(float, input().split())

    phi *= math.pi / 180
    g = 9.81

    t =  x1 / (v * math.cos(phi))
    y = v * t * math.sin(phi) - 1/2 * g * t * t

    safe = (y - h1) >= 1 and (h2 - y) >= 1

    print("Safe" if safe else "Not Safe")
