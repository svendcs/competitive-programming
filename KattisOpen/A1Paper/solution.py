import math

n = int(input())
count = [0]
count.extend(list(map(int, input().split())))

# print(count)
def side_length(size): #A1 is size 0
    n = size + 1
    return 2 ** (1/4 - n/2)

# def required(size): # A1 is size 0
#     if size == len(count):
#         return -1

#     if count[size] >= 1:
#         count[size] -= 1 # use one piece
#         return 0;
#     else: # construct a piece
#         rec1 = required(size+1)
#         rec2 = required(size+1)
#         if rec1 == -1 or rec2 == -1:
#             return -1
#         return side_length(size+1) + rec1 + rec2

# res = required(0)
# print("impossible" if res == -1 else res)

required = [0] * (n+1)
required[0] = 1
res = 0
for i in range(n):
    if required[i] > count[i]:
        m = required[i] - count[i]
        # print("Creating {} pieces of A{}".format(m, i+1))
        required[i+1] += m * 2 # create m pieces using the smaller size
        res += m * side_length(i + 1)

print(res if required[n] == 0 else "impossible")

