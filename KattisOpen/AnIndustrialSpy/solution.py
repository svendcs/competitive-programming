from itertools import permutations

# # Sieve of Era.. something
# m = 10000000
# is_prime = [True] * (m+2)
# is_prime[1] = False
# is_prime[0] = False
# for i in range(2, m+1):
#     if not is_prime[i]: continue
#     for j in range(i+i, m+1, i):
#         is_prime[j] = False

import math
def is_prime(n):
    if n == 1 or n == 0:
        return False
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

# print(is_prime)

for case in range(int(input())):
    n = input()
    c = 0
    numbers = set()
    for i in permutations(n):
        for j in range(0, len(i)):
            k = int("".join(i[j:]))
            numbers.add(k)

    for i in numbers:
        if(is_prime(i)):
            c += 1
    print(c)
