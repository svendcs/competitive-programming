a, b = map(int, input().split())

c = max(a,b)*2
if c == 0:
    print("Not a moose")
elif a == b:
    print("Even {}".format(c))
else:
    print("Odd {}".format(c))
