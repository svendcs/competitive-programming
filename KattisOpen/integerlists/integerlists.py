from collections import deque
for testcase in range(int(input())):
    program = input()
    n = int(input())
    
    inp = input()[1:-1]
    if len(inp) == 0:
        l = deque()
    else:
        l = deque(map(int, inp.split(",")))

    revsd = False
    error = False
    for c in program:
        if c == 'R':
            revsd = not revsd
        if c == 'D':
            if not l:
                print("error")
                error = True
                break
            if revsd:
                l.pop()
            else:
                l.popleft()
    if not error:
        if revsd:
            l = reversed(l)
        s = str(list(l)).replace(' ', '')
        print(s)
