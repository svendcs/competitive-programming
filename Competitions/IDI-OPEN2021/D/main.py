a, b, c, d = map(int, input().split())
count = 0

if a * b == c * d:
    print("{} * {} = {} * {}".format(a, b, c, d))
    count += 1
if a * b == c + d:
    print("{} * {} = {} + {}".format(a, b, c, d))
    count += 1
if a * b == c - d:
    print("{} * {} = {} - {}".format(a, b, c, d))
    count += 1
if d != 0 and a * b == c // d:
    print("{} * {} = {} / {}".format(a, b, c, d))
    count += 1

if a + b == c * d:
    print("{} + {} = {} * {}".format(a, b, c, d))
    count += 1
if a + b == c + d:
    print("{} + {} = {} + {}".format(a, b, c, d))
    count += 1
if a + b == c - d:
    print("{} + {} = {} - {}".format(a, b, c, d))
    count += 1
if d != 0 and a + b == c // d:
    print("{} + {} = {} / {}".format(a, b, c, d))
    count += 1

if a - b == c * d:
    print("{} - {} = {} * {}".format(a, b, c, d))
    count += 1
if a - b == c + d:
    print("{} - {} = {} + {}".format(a, b, c, d))
    count += 1
if a - b == c - d:
    print("{} - {} = {} - {}".format(a, b, c, d))
    count += 1
if d != 0 and a - b == c // d:
    print("{} - {} = {} / {}".format(a, b, c, d))
    count += 1

if b != 0 and a // b == c * d:
    print("{} / {} = {} * {}".format(a, b, c, d))
    count += 1
if b != 0 and a // b == c + d:
    print("{} / {} = {} + {}".format(a, b, c, d))
    count += 1
if b != 0 and a // b == c - d:
    print("{} / {} = {} - {}".format(a, b, c, d))
    count += 1
if b != 0 and d != 0 and a // b == c // d:
    print("{} / {} = {} / {}".format(a, b, c, d))
    count += 1

if count == 0:
    print("problems ahead")

