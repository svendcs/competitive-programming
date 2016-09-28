from queue import PriorityQueue

for case in range(int(input())):
    milk, cats = map(int, input().split())
    distances = [[0 for i in range(cats)] for j in range(cats)]
    for k in range(cats * (cats-1) // 2):
        i, j, d = map(int, input().split())
        distances[i][j] = d;
        distances[j][i] = d;

    visited = [False] * cats
    required = 0
    queue = PriorityQueue()
    queue.put((0, 0))

    while not queue.empty():
        item = queue.get()
        cat = item[1]
        distance = item[0]
        if visited[cat]: continue

        # print(item)
        visited[cat] = True
        required += distance + 1


        for i in range(cats):
            if visited[i]: continue
            queue.put((distances[cat][i], i))

    # print("{} milliliters of milk is required".format(required))
            
    print("yes" if required <= milk else "no")
