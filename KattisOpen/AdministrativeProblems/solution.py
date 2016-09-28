import math

cases = int(input())

for case in range(cases):
    n, m = map(int, input().split())
    cars = {}
    for i in range(n):
        car = input().split()
        cars[car[0]] = list(map(int, car[1:]))

    # print(cars)
    spies = {}
    events = []
    for i in range(m):
        event = input().split()
        event[0] = int(event[0])

        spy = {"car": None, "expense": 0, "consistent": True}
        if event[1] in spies:
            spy = spies[event[1]]
        else:
            spies[event[1]] = spy

        typ = event[2]

        if typ == "p":
            if spy["car"] is None:
                spy["car"] = event[3]
                spy["expense"] += cars[event[3]][1]
            else:
                spy["consistent"] = False
        elif typ == "r":
            if not spy["car"] is None:
                spy["expense"] += cars[spy["car"]][2] * int(event[3])
                spy["car"] = None
            else:
                spy["consistent"] = False
        else:
            assert(typ == "a")
            if not spy["car"] is None:
                spy["expense"] += math.ceil(cars[spy["car"]][0] * int(event[3]) / 100)
            else:
                spy["consistent"] = False

    for spy in spies.values():
        if not spy["car"] is None:
            spy["consistent"] = False

    for name in sorted(spies.keys()):
        spy = spies[name]
        print("{} {}".format(name, spy["expense"] if spy["consistent"] else "INCONSISTENT"))
