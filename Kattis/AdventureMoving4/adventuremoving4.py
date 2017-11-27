from sys import stdin

distance = int(input())
stations = [list(map(int, line.strip().split())) for line in stdin]
n = len(stations)

cost = [[-1 for i in range(n+1)] for j in range(201)]

def solve(i, fuel_required): # minimum price to get to i with j liters of fuel
    for j in range(0,i):

print(stations)

tank = 100
