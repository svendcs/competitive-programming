for testcase in range(int(input())):
    n = int(input())
    parties = list()
    for i in range(n):
        s, p = map(int, input().split())
        parties.append((s,p/100))
    mem = [[0 for i in range(n+2)] for j in range(77)]
    for seats in range(77):
        for i in reversed(range(n+1)):
            if seats == 0:
                mem[seats][i] = 1
                continue
            if i == n:
                mem[seats][i] = 0
                continue

            s, p = parties[i]
            mem[seats][i] = max(mem[max(seats-s, 0)][i+1] * p, mem[seats][i+1])
    print(mem[76][0] * 100)
