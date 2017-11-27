import sys

n = int(input())
days = [0]*30*12
for i in range(n):
    s = input()
    idx = (int(s[2:])-1) * 30 + (int(s[:2])-1)
    days[idx] += 1

current = sum(days[:30])
best = current
best_index = 0

for i in range(1, 30*12):
    current += days[(i+29) % (30*12)] - days[i-1]

    if current < best:
        best = current
        best_index = i;

print("{1:02d}{0:02d}".format(best_index // 30 + 1, best_index % 30 + 1))
