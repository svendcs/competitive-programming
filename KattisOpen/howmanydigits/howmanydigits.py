import sys
import math

sums = [0, 0]

for i in range(2, 1000000+1):
    sums.append(math.log(i, 10) + sums[i-1])

for line in sys.stdin:
    i = line.strip()
    if not i: break
    n = int(i)
    if n is 1 or n is 0:
        print(1)
    else:
        print((size_t)math.ceil(sums[n]))
