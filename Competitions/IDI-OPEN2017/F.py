N = int(raw_input())

l = []
# Block: lo, hi, amount, start index
blocks = [[0, 100, 0, 0]]

total = 0

last = None

for i in range(N):
	name, amount = raw_input().strip().split()
	if amount != '?':
		n = int(amount)
		total += n
		l.append([name, n, n])
		last = n
		blocks[-1][0] = n
		blocks.append([0, n, 0, i + 1])
	else:
		l.append([name, None, None])
		blocks[-1][2] += 1

blocks = filter(lambda b: b[2] != 0, blocks)

#print(blocks)

blocksums = []

for b in blocks:
	blocksums.append((b[0] * b[2], b[1] * b[2]))

for bi, b in enumerate(blocks):
	lower = 0
	upper = 0
	for bj, bs in enumerate(blocksums):
		if bi == bj:
			continue

		lower += bs[0]
		upper += bs[1]

	for i in range(b[2]):
		k2 = i
		k1 = b[2] - i - 1
		loval = None
		hival = None
		for c in range(b[0], b[1] + 1):
			lo = b[0] * k1 + c * k2 + c + total + lower
			hi = c * k1 + b[1] * k2 + c + total + upper

			if lo <= 100 <= hi:
				if loval == None:
					loval = c

				hival = c


		l[b[3] + i][1] = loval
		l[b[3] + i][2] = hival


for name, lo, hi in l:
	print('%s %s %s' % (name, lo, hi))


