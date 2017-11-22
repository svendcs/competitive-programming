numbers = sorted(map(int, input().split()))

res = []

for c in input():
    if c == 'A':
        res.append(numbers[0])
    if c == 'B':
        res.append(numbers[1])
    if c == 'C':
        res.append(numbers[2])

print(" ".join(map(str, res)))

