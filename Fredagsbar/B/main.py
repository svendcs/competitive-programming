import sys
w, h = map(int, input().split())

full = 0
half = 0
for x in range(h):
    if x % 2 is 0:
        full += w // 2
        half += w % 2
    else:
        full += (w-1) // 2
        half += 1 + ((w-1) % 2)
print("{} {}".format(full, half))
