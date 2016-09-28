def empty_intersection(a, b):
    if a[1] < b[0]:
        return True
    return False

def intersection(a, b):
    return (max(a[0], b[0]), min(a[1], b[1]))

n = int(input())

minions = sorted([list(map(int, input().split())) for i in range(n)])

rooms = 1
insect = (1, 2*n)
for minion in minions:
    if empty_intersection(insect, minion): # this minion can't be covered by the previous room
        insect = minion
        rooms += 1
    else:
        insect = intersection(insect, minion)

print(rooms)
