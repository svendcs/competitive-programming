import math
r, c = map(int, input().split())

a1 = math.pi * (r-c)**2
a2 = math.pi * r**2
print(a1/a2 * 100)


