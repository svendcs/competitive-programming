from itertools import permutations

def solution(n):
    if n is 1:
        return [[1]]

    rec = solution(n-1)

    res = []
    for i in range(len(rec)):
        for j in range(len(rec[i])+1):
            k = j if i % 2 == 1 else (len(rec[i])-j)
            s = rec[i][:k] + [n] + rec[i][k:]
            res.append(s)
    return res

for perm in solution(int(input())):
    print(" ".join(map(str, perm)))
