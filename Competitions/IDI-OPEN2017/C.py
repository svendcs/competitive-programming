T, K = map(int, raw_input().split())

v = 0

for t in range(2, T + 1):
	v = (v + K) % t

print(v)
