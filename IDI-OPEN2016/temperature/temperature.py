x, y = map(int, input().split())


if y == 1:
    if x == 0:
        print("ALL GOOD")
    else:
        print("IMPOSSIBLE")
else:
    print((x/y)/(1/y-1))

