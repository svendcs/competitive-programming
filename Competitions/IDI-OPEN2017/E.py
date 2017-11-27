from math import *

N, K = map(int, raw_input().split())

x = N
i = 1

while x > 0:
	x = x - int(ceil(x * 1.0 / K))
	#print(x)
	i += 1

print(i)
