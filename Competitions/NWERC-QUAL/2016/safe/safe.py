safe = list(map(int, input().split()))
safe.extend(list(map(int, input().split())))
safe.extend(list(map(int, input().split())))

def perform_press(safe, x, y):
    for i in range(0,3):
        if i != x:
            safe[y * 3 + i] = (safe[y * 3 + i] + 1) % 4
        if i != y:
            safe[i * 3 + x] = (safe[i * 3 + x] + 1) % 4
    safe[y * 3 + x] = (safe[y * 3 + x] + 1) % 4

def is_open(safe):
    for y in safe:
        if y != 0:
            return False
    return True

# Try all 3^9 possibilities
presses = [0,0,0,0,0,0,0,0,0]

# print(safe)
# print(is_open(safe, [1, 0, 0, 0, 2, 1, 0, 0, 0]))

inf = 2000000
best = inf
current = 0
while True:
    if current == 3 * 9:
        break

    if is_open(safe):
        best = min(best, current)

    for i in range(len(presses)):
        perform_press(safe, i % 3, i // 3)
        presses[i] += 1
        current += 1
        if presses[i] > 3:
            presses[i] = 0
            current -= 4
        else:
            break

print(best if best != inf else "-1")

