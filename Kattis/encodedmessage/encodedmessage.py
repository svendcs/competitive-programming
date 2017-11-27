import math

n = int(input())
for i in range(n):
    s = input()
    w = int(math.sqrt(len(s)))
    rotated = ""
    for x in reversed(range(w)):
        for y in range(w):
            rotated += s[x + y * w]
    print(rotated)
