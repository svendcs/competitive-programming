t = int(input())

def str_to_int(s, n):
    res = 0
    i = 0
    for el in reversed(s):
        i += 1
        res = res * 10 
        if el == "lower":
            res += 3
        if el == "middle":
            res += 2
        if el == "upper":
            res += 1
    while i < n:
        res = res * 10 + 2
        i += 1
    return res

def get_class(s):
    return s[1].split()[0].split('-')

for i in range(t):
    n = int(input())
    items = []
    for j in range(n):
        items.append(input().split(": "))
    m = max(len(get_class(item)) for item in items)
    res = sorted((str_to_int(get_class(item), m), item[0]) for item in items)

    for item in res:
        print(item[1])
    print("=" * 30)
