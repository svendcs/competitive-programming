from math import *

N, M, K = map(int, raw_input().split())
plotr = map(int, raw_input().split())
houser = map(int, raw_input().split())
sidel = map(int, raw_input().split())

l = []

for r in houser:
	l.append(r)

for r in sidel:
	l.append(r * (2**0.5) / 2.0)

l.sort()
plotr.sort()

#print(l)
#print(plotr)

c = 0
i = 0
j = 0
while True:
	if i == M + K:
		break

	if j == N:
		break

	if l[i] < plotr[j]:
		c += 1
		i += 1
		j += 1
	else:
		j += 1

print(c)
