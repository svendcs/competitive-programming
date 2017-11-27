import sys
w, h, b, n = map(int, input().split())

m = []
for i in range(h):
    s = input()
    m.append(s[1:w+1])
input()

buckets = {}
for i in range(b):
    t, v = input().split()
    buckets[t] = int(v)

score = [[0 for i in range(w)] for j in range(h)]
for i in range(0, w, 2):
    score[h-1][i] = buckets[m[h-1][i]]

for i in range(1, w, 2):
    score[h-1][i] = (score[h-1][i-1] + score[h-1][i+1])/2

for i in reversed(range(0, h-1)):
    for j in range(0, w):
        if m[i][j] == ' ':
            score[i][j] = score[i+1][j]
        else:
            if j == 0:
                score[i][j] = score[i+1][j+1]
            elif j == w-1:
                score[i][j] = score[i+1][j-1]
            else:
                score[i][j] = (score[i+1][j-1] + score[i+1][j+1]) / 2

balls = map(int, input().split())
total = 0
for ball in balls:
    total += score[0][ball-1]
print(total)
