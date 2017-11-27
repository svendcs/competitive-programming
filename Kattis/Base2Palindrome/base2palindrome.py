palindromes = set([0, 1])

def to_string(a):
    res = ""
    while a > 0:
        res += str(a%2)
        a //= 2
    return res[::-1]

n = 1
while len(palindromes) < 60000:
    s = to_string(n)
    rev = s[::-1]
    a = int(rev + "0" + s)
    b = int(rev + "1" + s)
    c = int(rev + s)
    palindromes.add(a)
    palindromes.add(b)
    palindromes.add(c)

    n += 1
    while n % 2 is 0:
        n += 1

m = int(input())

res = sorted(list(palindromes))
print(res[:100])
