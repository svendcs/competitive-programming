import sys

def optimal(goal, dice, worm):
    if dice == 0:
        return (goal <= 0 && worm ? 1 : 0)

    s = 0
    for i in range(6 ** dice): # iterate over all dice outcomes
        best = 0
        for j in range(6): # try all combinations of putting aside
            count = 0;
            t = i;
            for k in range(dice):
                if t % 6 == j:
                    count += 1
                i // 6
            if count == 0: # not possible
                continue
            res = (j == 5 ? optimal(goal, dice - count, True) : optimal*
            if (j == 5)

        s += best
    return s / (6 ** dice)
# for n in map(int, sys.stdin):
#     print(optimal(n, 6))

print(optimal(10, 3))
