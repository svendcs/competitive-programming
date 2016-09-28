word = input()
n = len(word)

best = word

for i in range(1, n-1):
    for j in range(i+1, n):
        current = list(reversed(word[0:i]))
        current.extend(list(reversed(word[i:j])))
        current.extend(list(reversed(word[j:])))
        current = "".join(current)

        if current < best:
            best = current

print(best)
