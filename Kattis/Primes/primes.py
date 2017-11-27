def visit(numbers, x, y, primes, i, m):
    # print(primes, i, m)
    if i == len(primes):
        if x <= m:
            numbers.append(m)
        return

    new_m =  m
    for j in range(0, 32):
        if new_m > y: break
        visit(numbers, x, y, primes, i+1,new_m)
        new_m *= primes[i]
    
while True:
    n = int(input())
    if n == 0: break

    primes = list(sorted(map(int, input().split())))
    x, y = map(int, input().split())

    numbers = []
    visit(numbers, x, y, primes, 0, 1)

    if not len(numbers) is 0:
        print(",".join(map(str, sorted(numbers))))
    else:
        print("none")

