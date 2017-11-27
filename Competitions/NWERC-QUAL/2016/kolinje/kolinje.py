from fractions import Fraction

n = int(input())

participants = [list(map(int, input().split())) for i in range(n)]
S = sum([p[1] for p in participants])
minPossible = Fraction(0)
maxPossible = Fraction(10**9)

for i in range(0, n-1):
        a = participants[i]
        b = participants[i+1]

        if a[0] >= b[0]: # Already the correct order
            if a[1] >= b[1]: # It is never possible for b to eat more than a
                continue

            l = Fraction((b[0]-a[0])*S, a[1]-b[1])
            if l < maxPossible:
                maxPossible = l
        else:
            if a[1] <= b[1]: # It is never possible for a to eat more than b
                continue

            l = Fraction((a[0]-b[0])*S, b[1]-a[1])
            if l > minPossible:
                minPossible = l

possible = maxPossible >= minPossible

print(float(minPossible) if possible else "-1")
