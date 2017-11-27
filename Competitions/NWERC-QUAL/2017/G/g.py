import math

def dist(a, b):
    return math.sqrt((b[0] - a[0])**2 + (b[1]-a[1])**2)


n = int(input())

shapes = input()

triangley = math.sqrt(1 - 1/4)
if shapes.count('T') == n: # special case when all triangles
    print(n + n - 1 + 2)
    exit()

circumference = 0;
left_point = 0
right_point = 0

# First calculate upper hull and sides
if shapes[0] == 'C':
    left_point = 0.5
    circumference += (2 * math.pi * 0.5)/4
if shapes[0] == 'S':
    left_point = 0
    circumference += 1
if shapes[0] == 'T': # find first non-triangle
    i = 1;
    circumference += 1
    while shapes[i] == 'T':
        i += 1

    if shapes[i] == 'S':
        left_point = i
        circumference += dist((0.5, triangley), (i, 1))
    if shapes[i] == 'C':
        left_point = i + 0.5

        centerp = (i + 0.5, 0.5)
        trianglep = (0.5, triangley)

        c = dist(centerp, trianglep)
        b = 0.5
        a = math.sqrt(c**2 - b**2)

        alpha = math.asin(a/c)
        a2 = abs(trianglep[1] - centerp[1])
        gamma = math.asin(a2/c)
        beta = math.pi / 2 - gamma - alpha

        circumference += beta/2 + a

if shapes[n-1] == 'C':
    right_point = n-0.5
    circumference += (2 * math.pi * 0.5)/4
if shapes[n-1] == 'S':
    right_point = n
    circumference += 1
if shapes[n-1] == 'T': # find first non-triangle
    circumference += 1
    i = n-2;
    while shapes[i] == 'T':
        i -= 1

    if shapes[i] == 'S':
        right_point = i+1
        circumference += dist((n-0.5, triangley), (i+1, 1))
    if shapes[i] == 'C':
        right_point = i + 0.5

        centerp = (i + 0.5, 0.5)
        trianglep = (n-0.5, triangley)

        c = dist(centerp, trianglep)
        b = 0.5
        a = math.sqrt(c**2 - b**2)

        alpha = math.asin(a/c)
        a2 = abs(trianglep[1] - centerp[1])
        gamma = math.asin(a2/c)
        beta = math.pi / 2 - gamma - alpha

        circumference += beta/2 + a

circumference += right_point - left_point

# now calculate lower hull
circumference += n-2
if shapes[0] == 'C':
    circumference += (2 * math.pi * 0.5)/4 + 0.5
else:
    circumference += 1

if shapes[n-1] == 'C':
    circumference += (2 * math.pi * 0.5)/4 + 0.5
else:
    circumference += 1

print(circumference)
