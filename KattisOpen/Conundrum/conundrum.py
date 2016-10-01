diff = 0
i = 0
for c in input().lower():
    per = "per"
    if c != per[i]:
        diff += 1
    i = (i+1) % 3

print(diff)
