import math

n, k = map(int, input().split())

times = [0] * 101001
for i in range(n):
    r = int(input())
    times[r] += 1
    times[r+1000] -= 1

m = 0
c = 0
for i in range(0, 100001):
    c += times[i]
    m = max(m,c)

print(math.ceil(m/k))
    
