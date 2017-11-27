operators = ['+', '-', '//', '*']

for case in range(int(input())):
    n = int(input())
    found = False
    for a in operators:
        if found: break
        for b in operators:
            if found: break
            for c in operators:
                if found: break
                exp = "4 {} 4 {} 4 {} 4".format(a, b, c)
                res = eval(exp)
                if res == n:
                    print(exp.replace("//", "/"))
                    found = True
    if not found:
        print("no solution")
